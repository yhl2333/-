#include <rtthread.h>
#define DBG_TAG "main"  // 日志标签
#define DBG_LVL DBG_LOG // 日志级别
#include <rtdbg.h>  //日志函数需包含的头文件

#define THREAD_STACK_SIZE   1024//线程栈大小
/* 两个线程的优先级分别定义 */
#define THREAD_PRIORITY_LED     20
#define THREAD_PRIORITY_BEEP     20
#define THREAD_TIMESLICE    10//线程时间片大小为10个系统滴嗒，默认是10ms
/* 本任务我们使用序编译宏进行选择编译，当定义以下宏时，将开启调度器钩子的功能*/
/*#define SCHEDULER_HOOK*/

ALIGN(RT_ALIGN_SIZE)
static char beep_stack[THREAD_STACK_SIZE];
static struct rt_thread beepThread;
static rt_thread_t TidLed = RT_NULL;

#ifdef SCHEDULER_HOOK
/* 定义调度钩子函数 */
static void hook_of_scheduler(struct rt_thread* from, struct rt_thread* to)
{
    //打印出调度信息：从一个线程切换到另一个线程运行
    rt_kprintf("from: %s -->  to: %s \n", from->name , to->name);
}
#endif

void beep_thread_entry(void *parameter)
{
    rt_thread_t tid;
    int count=0;//为了观察方便，我们只打印出前5个调度过程

    while (1){
        tid = rt_thread_self();//获取本线程的句柄
        /*打印线程的名字和当前计数变量的值*/
        LOG_D("thread name:%s count=%d\n",tid->name, count);
        if(count++ == 5)// 线程循环5次后退出
            break;
    }
    /* 线程退出时打印退出信息 */
    LOG_D("thread %s exit\n",tid->name);
}

void led_thread_entry()//线程入口函数
{
    int count=0;
    rt_thread_t tid;
    while(1){
        tid = rt_thread_self();//获取本线程的句柄
        /*打印线程的名字和当前计数变量的值*/
        LOG_D("thread name:%s count=%d\n",tid->name,count);
        if(count++ == 5) // 线程循环5次后退出
            break;
}
/* 线程退出时打印退出信息 */
    LOG_D("thread %s exit\n",tid->name);
}
/*main函数主要完成线程的创建工作*/
int main(void)
{
    int ret;

#ifdef SCHEDULER_HOOK
    /* 设置调度器钩子 */
    rt_scheduler_sethook(hook_of_scheduler);
#endif

TidLed = rt_thread_create("LED", led_thread_entry, 
RT_NULL,THREAD_STACK_SIZE, 
THREAD_PRIORITY_LED, THREAD_TIMESLICE);
    if (TidLed != RT_NULL)
        rt_thread_startup(TidLed);
    else {
        LOG_D("can not create LED thread!");
        return -1;
    }

    ret = rt_thread_init(&beepThread,
                            "BEEP",
                            beep_thread_entry,
                            RT_NULL,
                            &beep_stack[0],
                            sizeof(beep_stack),
                            THREAD_PRIORITY_BEEP,
                            THREAD_TIMESLICE);
    if (ret == RT_EOK)
        rt_thread_startup(&beepThread);
    else {
        LOG_D("can not init beep thread!");
        return -1;
    }

    return RT_EOK;
}
