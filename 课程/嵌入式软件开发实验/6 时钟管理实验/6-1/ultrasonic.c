#include <rtthread.h>
#include <rtdevice.h>
#include <drv_common.h>
#define DBG_TAG "ULTR"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
/* 序编译宏定义，如果要使用定时器，可以打开ULT_USE_TIMER宏，在本任务中，暂时不使用定时器，定时器的使用，我们会在任务6-3进行介绍 */
/* #define ULT_USE_TIMER */

/* 超声波模块结构体定义 */
struct ultr{
    /*用于线程间同步的信号量，测量线程测量到距离后，通过此信号量通知读取线程*/
struct rt_semaphore sem; 
/*以下斜体部分代码在本任务中不使用*/
#ifdef ULT_USE_TIMER
    struct rt_timer timer;  //等待ECHO信号的定时器
    int echoTimeOut;        //等待ECHO信号的超时时间
#endif
    rt_base_t trigPin; /* RTIG引脚 */
    rt_base_t echoPin; /* ECHO引脚 */
    uint32_t dis;      /* 测量到的距离 */
};

/* 超声波模块实例定义，表示某个超声波模块 */
struct ultr hcsr04={
.echoPin = GET_PIN(B, 1), /* ECHO引脚定义*/
.trigPin = GET_PIN(B, 0),  /* RTIG引脚定义*/
#ifdef ULT_USE_TIMER
    .echoTimeOut = 0,
#endif
};
#define MODULE_NAME "ultr_hcsr04"   /*模块名字定义*/
#define THREAD_STACK_SIZE   1024    //栈大小
#define THREAD_PRIORITY     19      //优先级
#define THREAD_TIMESLICE    10      //时间片

#ifdef ULT_USE_TIMER
void time_out()
{
    LOG_D("timeout");
    hcsr04.echoTimeOut = 1;
}
#endif

/* 获取距离数据 */
uint32_t ultr_get_distence(void)
{
    rt_sem_take(&hcsr04.sem, RT_WAITING_FOREVER);//等待测量完成
    return hcsr04.dis; //返回测量结果
}

/* 获取tick时间和SYSTICK计数寄存器的当前值，目的是得到更高精度的时间参数 */
static void ultr_get_clock(rt_uint32_t* tick,rt_uint32_t* clock)
{
    *clock = SysTick->VAL;
    *tick = rt_tick_get();
}
/*测量线程入口函数，传入的参数为测量的时间间隔，单位是毫秒*/
static void ultr_thread_entry(void *interval)
{
    rt_tick_t t1,t2,clk1,clk2;//定义变量

    while(1){
        /* 向TRIG引脚输出触发信号，先写高电平，再写低电平，产生10us脉冲 */
        rt_pin_write(hcsr04.trigPin, PIN_HIGH);
        rt_hw_us_delay(10);
        rt_pin_write(hcsr04.trigPin, PIN_LOW);

        /* 等待模块返回测量结果，引脚变为高电平表示有测量结果 */
#ifdef ULT_USE_TIMER
        rt_timer_start(&hcsr04.timer);
        while(PIN_LOW == rt_pin_read(hcsr04.echoPin) && !hcsr04.echoTimeOut);
        if(hcsr04.echoTimeOut) //等待ECHO信号超时，退出本次测量
            goto exit;
        else
            rt_timer_stop(&hcsr04.timer); //收到ECHO信号，停止定时器
#else
        while(PIN_LOW == rt_pin_read(hcsr04.echoPin)); //一直等待ECHO信号
#endif
        /* 记录此时的系统时间t1,clk1 ，即ECHO信号的上升沿时间*/
        ultr_get_clock(&t1,&clk1);
        /* 等待返回的脉冲结束 */
#ifdef ULT_USE_TIMER
        rt_timer_start(&hcsr04.timer);
        while(PIN_HIGH==rt_pin_read(hcsr04.echoPin) && !hcsr04.echoTimeOut);
        if(hcsr04.echoTimeOut) //等待ECHO信号结束超时，退出本次测量
            goto exit;
        else
            rt_timer_stop(&hcsr04.timer);
#else
        while(PIN_HIGH == rt_pin_read(hcsr04.echoPin));//等待ECHO信号结束
#endif
        /* 记录此时的系统时间t2,clk2 ，即ECHO信号的下降沿时间*/
        ultr_get_clock(&t2,&clk2);
        
        /*计算距离，单位为mm,注意RT_TICK_PER_SECOND默认为1000*/
        LOG_D("t1=%d,t2=%d,clk1=%d,clk2=%d",t1,t2,clk1,clk2);
        /*计算时要注意，变量可能发生溢出*/
        if(clk2<=clk1)
            hcsr04.dis = (t2 - t1)*170 + (clk1 - clk2)*170/(SysTick->LOAD+1);
        else {
            hcsr04.dis = (t2 - t1-1)*170 + (SysTick->LOAD + 1 - clk1 + clk2)*170/(SysTick->LOAD+1);
        }
#ifndef ULT_USE_TIMER
        rt_sem_release(&hcsr04.sem);//释放信号量，通信读取线程来读测量结果
#else
        exit:
        if(!hcsr04.echoTimeOut)
            rt_sem_release(&hcsr04.sem);
        else {
            hcsr04.echoTimeOut = 0;
        }
#endif
        rt_thread_mdelay(*(rt_int32_t *)interval);//等待下一次测量
    }
}
/* 超声波模块初始化函数，主要设置引脚的模式和初始电平，最后创建测量线程 */
void ultr_init(rt_int32_t* interval)
{
    rt_thread_t tid = RT_NULL;
#ifdef ULT_USE_TIMER
    rt_timer_init(&hcsr04.timer,MODULE_NAME, time_out,
                 RT_NULL, 1000,
                 RT_TIMER_FLAG_ONE_SHOT);
#endif
    rt_sem_init(&hcsr04.sem, MODULE_NAME, 0, RT_IPC_FLAG_PRIO);
    /* 把TRIG引脚设置为输出模式 */
    rt_pin_mode(hcsr04.trigPin, PIN_MODE_OUTPUT);
    /* 初始电平设置为低电平 */
    rt_pin_write(hcsr04.trigPin, PIN_LOW);
    /* 把ECHO引脚设置为输入模式 */
    rt_pin_mode(hcsr04.echoPin, PIN_MODE_INPUT);
    /*创建测量线程*/
    tid = rt_thread_create(MODULE_NAME,
                            ultr_thread_entry,
                            interval,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tid != RT_NULL)
        rt_thread_startup(tid);
    else {
        LOG_E("cannot create thread %s",MODULE_NAME);
    }

}
