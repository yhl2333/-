#include <rtthread.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "car_led.h"    //包含LED控制模块头文件
#include "car_beep.h"   //包含蜂鸣器控制模块头文件

#define THREAD_STACK_SIZE   1024   //定义线程栈大小
#define THREAD_PRIORITY     20     //定义线程优先级
#define THREAD_TIMESLICE    10     //定义线程时间片

/* 栈首地址必须系统对齐 */
ALIGN(RT_ALIGN_SIZE)
static char beep_stack[THREAD_STACK_SIZE];  //定义栈空间
static struct rt_thread beepThread;    //静态方式定义beep线程控制块
rt_thread_t TidLed = RT_NULL;  //动态方式定义LED线程句柄

int main(void)
{
    int ret;

    /* 动态方式创建线程 */
    TidLed = rt_thread_create("LED", 
led_thread_entry, 
RT_NULL,
THREAD_STACK_SIZE, 
THREAD_PRIORITY, 
THREAD_TIMESLICE);
    if (TidLed != RT_NULL)//判断线程是否成功创建
        rt_thread_startup(TidLed);//成功则启动线程
    else {//否则打印日志并即出
        LOG_D("can not create LED thread!");
        return -1;
    }

    /* 采用静态方式初始化线程 */
    ret = rt_thread_init(&beepThread,
                            "BEEP",
                            beep_thread_entry,
                            RT_NULL,
                            &beep_stack[0],
                            sizeof(beep_stack),
                            THREAD_PRIORITY,
                            THREAD_TIMESLICE);
    if (ret == RT_EOK) //判断线程是否成功创建
        rt_thread_startup(&beepThread); //成功则启动线程
    else { //否则打印日志并即出
        LOG_D("can not init beep thread!");
        return -1;
    }

    return RT_EOK;
}
void stop_led_thread(void)//删除led线程命令
{
    rt_thread_delete(TidLed);//动态创建的线程用delete删除
}
void stop_beep_thread(void) //删除beep线程命令
{
    rt_thread_detach(&beepThread);//静态初始化的线程用detach删除
}

/* 导出到 msh 命令列表中*/
MSH_CMD_EXPORT(stop_led_thread, delete led thread);
MSH_CMD_EXPORT(stop_beep_thread, delete beep thread);
