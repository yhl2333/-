#include <rtthread.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "car_led.h"
#include "car_beep.h"
#define THREAD_STACK_SIZE   1024
#define THREAD_PRIORITY     20
#define THREAD_TIMESLICE    10

ALIGN(RT_ALIGN_SIZE)
static char beep_stack[THREAD_STACK_SIZE];
static struct rt_thread beepThread;
static rt_thread_t TidLed = RT_NULL;

int main(void)
{
    int ret;

TidLed = rt_thread_create("LED", led_thread_entry, 
RT_NULL,THREAD_STACK_SIZE,
THREAD_PRIORITY, THREAD_TIMESLICE);
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
                            THREAD_PRIORITY,
                            THREAD_TIMESLICE);
    if (ret == RT_EOK)
        rt_thread_startup(&beepThread);
    else {
        LOG_D("can not init beep thread!");
        return -1;
    }

    return RT_EOK;
}
void stop_led_thread()//暂停运行
{
     led_stop_flag(1);
}
void resume_led_thread()//恢复运行
{ 
led_stop_flag(0);//先设置为运行
rt_thread_resume(TidLed);//再恢复线程
    return;
}
/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(resume_led_thread, resume led thread);//唤醒命令
MSH_CMD_EXPORT(stop_led_thread, stop led thread);
