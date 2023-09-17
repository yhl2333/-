#include <rtthread.h>
#define DBG_TAG "main"       //日志TAG
#define DBG_LVL DBG_LOG      //日志级别
#include <rtdbg.h>           //日志打印头文件

#define THREAD_STACK_SIZE   1024   //栈大小
#define THREAD_PRIORITY_LED     20 //LED线程优先级
#define THREAD_TIMESLICE    10     //时间片

#define THREAD_PRIORITY_BEEP     19 //BEEP线程优先级
/* 以下为两个序编译宏定义，用于选择哪些代码参与编译 */
#define THREAD_CONTROL          //使能线程控制功能
#define USE_THREAD_YIELD      //定义此宏使用yield函数让出cpu，否则使用schedule

ALIGN(RT_ALIGN_SIZE)   //栈对齐
static char beep_stack[1024];  //栈内存
static struct rt_thread beepThread;   //线程控制块
static rt_thread_t TidLed = RT_NULL; //线程句柄

void beep_thread_entry(void *parameter) //beep线程入口函数 
{
    rt_thread_t tid;
    int count=0;

    for(count=0;count<6;count++)
    {
        tid = rt_thread_self();
        LOG_D("thread %s count=%d",tid->name, count);//打印出线程名字和运行次数
#ifdef USE_THREAD_YIELD
        rt_thread_yield();//使用yield函数让出cpu
#else
        rt_schedule();//使用schedule让出cpu
#endif
    }

    LOG_D("thread %s exit",tid->name); //退出后打印退出信息
}

void led_thread_entry()//led线程入口函数
{
    int count=0;
    rt_thread_t tid;
    for(count=0;count<6;count++)
    {
        tid = rt_thread_self();
        LOG_D("thread %s count=%d",tid->name, count);
#ifdef USE_THREAD_YIELD
        rt_thread_yield();//使用yield函数让出cpu
#else
        rt_schedule();//使用schedule让出cpu
#endif
    }
    LOG_D("thread %s exit",tid->name);
}

int main(void)
{
    int ret;
#ifdef THREAD_CONTROL
    rt_uint8_t priority=21;
#endif

    /*创建LED线程*/
    TidLed = rt_thread_create("LED",
                            led_thread_entry,
                            RT_NULL,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY_LED,
                            THREAD_TIMESLICE);
    /*创建BEEP线程*/
    ret = rt_thread_init(&beepThread,
                            "BEEP",
                            beep_thread_entry,
                            RT_NULL,
                            &beep_stack[0],
                            sizeof(beep_stack),
                            THREAD_PRIORITY_BEEP,
                            THREAD_TIMESLICE);

    if (ret == RT_EOK)
        rt_thread_startup(&beepThread); /*启动线程*/
    else {
        LOG_D("can not init beep thread!");
        return -1;
    }

    if (TidLed != RT_NULL)
        rt_thread_startup(TidLed); /*启动线程*/
    else {
        LOG_D("can not create LED thread!");
        return -1;
    }
#ifdef THREAD_CONTROL
    /*改变线程优先级*/
    rt_thread_control(TidLed, RT_THREAD_CTRL_CHANGE_PRIORITY, &priority);
    rt_thread_control(&beepThread, RT_THREAD_CTRL_CHANGE_PRIORITY, &priority);
#endif
    return RT_EOK;
