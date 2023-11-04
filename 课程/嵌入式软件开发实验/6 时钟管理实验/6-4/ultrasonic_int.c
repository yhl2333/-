#include <rtthread.h>
#include "ultrasonic_int.h"
#define DBG_TAG "ULTR"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

/* 定义时间相关的变量 */
static rt_tick_t t1,t2,clk1,clk2;
#define TIME_OUT_DEFAULT 1000 //默认的超时等待时间
/* 获取tick时间和SYSTICK计数寄存器的当前值 */
void ultr_get_clock(rt_uint32_t* tick,rt_uint32_t* clock)
{
    *tick = rt_tick_get();
    *clock = SysTick->VAL;
}
/* ECHO信号的中断回调函数 */
void echo_callback(void *args)
{
struct ultr* ul = (struct ultr*)args;
/*如果模块状态为已发出TRIG信号并且ECHO引脚为高电平，说明ECHO上升沿到达*/
    if((ULTRA_STATE_TRIG==ul->state)&&(PIN_HIGH==rt_pin_read(ul->echoPin)))
    {
        //LOG_D("echoup val:%d",rt_pin_read(hcsr04.echoPin));
        /* 记录此时的系统时间t1,clk1 */
        ultr_get_clock(&t1,&clk1);
        ul->state++;//改变超声波模块状态为已收到ECHO信号的上升沿
}
/*如果模块状态为已收到ECHO信号并且ECHO引脚为低电平，说明ECHO下降沿到达*/
    else if( (ULTRA_STATE_ECHO_S  == ul->state) && (PIN_LOW == rt_pin_read(ul->echoPin)) ){
        //LOG_D("echodown val:%d",rt_pin_read(hcsr04.echoPin));
        /* 记录此时的系统时间t2,clk2 */
        ultr_get_clock(&t2,&clk2);
        ul->state++;//改变超声波模块的状态
        /* 当收到ECHO信号的下降沿时，发送号量通知等待线程进行距离计算 */
        rt_sem_release(&ul->sem);
    }
    return;
}
/* 超声波模块初始化函数，主要设置引脚的模式和初始电平 */
void ultr_init(struct ultr* ul)
{
    /* 初始化信号量 */
    rt_sem_init(&ul->sem, ul->name, 0, RT_IPC_FLAG_PRIO);

    /* 把TRIG引脚设置为输出模式  */
    rt_pin_mode(ul->trigPin, PIN_MODE_OUTPUT);
    /* 初始电平设置为低电平 */
    rt_pin_write(ul->trigPin, PIN_LOW);

    /* 把ECHO引脚设置为输入模式 */
    rt_pin_mode(ul->echoPin, PIN_MODE_INPUT);

    /* 绑定中断，双边沿触发模式，上断回调函数名为echo_callback */
rt_pin_attach_irq(ul->echoPin, PIN_IRQ_MODE_RISING_FALLING, echo_callback, ul);
    if(ul->timeout==0)
        ul->timeout = TIME_OUT_DEFAULT; 
    /* 设置超声波模块为已初始化 */
    ul->state = ULTRA_STATE_INIT;
}
/*测量距离，参数为超声波模块指针，用于指定使用哪个超声波模块进行测量，本任务支持多模块*/
rt_int32_t ultr_get_distence(struct ultr* ul)
{
    rt_err_t ret;
    /* 未初始化，先进行初始化  */
    if(ULTRA_STATE_NULL == ul->state){
        ultr_init(ul);
        LOG_D("%s init ok!",ul->name);
    }
    /* 使能中断，准备接收ECHO信号  */
    rt_pin_irq_enable(ul->echoPin, PIN_IRQ_ENABLE);

    /* 向TRIG引脚输出触发信号，先写高电平，再写低电平，产生10us脉冲 */
    rt_pin_write(ul->trigPin, PIN_HIGH);
    rt_hw_us_delay(10);
    rt_pin_write(ul->trigPin, PIN_LOW);

    ul->state=ULTRA_STATE_TRIG;//状态设置为TRIG信号已发送
    /* 阻塞等待ECHO信号量，如果没有ECHO信号，线程会等待一段时间后退出  */
    ret = rt_sem_take(&ul->sem, ul->timeout);
    /* ECHO信号收到后，可以关闭中断了  */
    rt_pin_irq_enable(ul->echoPin, PIN_IRQ_DISABLE);
    if(RT_EOK == ret)
    {
        /*计算距离，单位为mm,注意RT_TICK_PER_SECOND默认为1000*/
        LOG_D("t1=%d,t2=%d,clk1=%d,clk2=%d",t1,t2,clk1,clk2);
        if(clk2<=clk1)
        {
            ul->dis = (t2 - t1)*170 + (clk1 - clk2)*170/(SysTick->LOAD+1);
        }
        else {
            ul->dis = (t2 - t1-1)*170 + (SysTick->LOAD + 1 - clk2 + clk1)*170/(SysTick->LOAD+1);
        }
        ul->state = ULTRA_STATE_END;//把超声波模块设置测量完成状态
        LOG_D("distance is:%u mm",ul->dis);
        return ul->dis;
    }
    else {
        LOG_D("%s timeout",ul->name);
        return -1;
    }
}
/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(ultr_get_distence, ultrasonic get distence);
