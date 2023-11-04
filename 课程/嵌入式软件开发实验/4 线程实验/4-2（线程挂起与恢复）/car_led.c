#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"

#define DBG_TAG "LED"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <stdlib.h>
#include "car_led.h"
/* 定义左右转向灯的控制引脚 */
#define LedLeft GET_PIN(D, 8)
#define LedRight GET_PIN(D, 9)
#define LedOn(pin) rt_pin_write(pin, PIN_LOW)
#define LedOff(pin) rt_pin_write(pin, PIN_HIGH)

enum led_mode LedMod=LED_MODE_STOP;
void led_set_mode(enum led_mode m)
{
    LedMod = m;
}
/* 暂停运行标志变量，0表示运行，1表示暂停 */
static int stopFlag=0;
void led_thread_entry()
{
    rt_pin_mode(LedLeft, PIN_MODE_OUTPUT);
    rt_pin_mode(LedRight, PIN_MODE_OUTPUT);
while(1){
    /*判断是否暂停运行*/
        if(stopFlag)
        {
            rt_thread_suspend(rt_thread_self());//挂起线程，只能自已挂起自已
            rt_schedule();//使用suspend挂起线程后，需手动进行线程上下文切换
        }
        switch(LedMod)
        {
        case LED_MODE_STOP:
            LedOff(LedLeft);
            LedOff(LedRight);
            break;
        case LED_MODE_Double:
            LedOn(LedLeft);
            LedOn(LedRight);
            rt_thread_mdelay(500);
            LedOff(LedLeft);
            LedOff(LedRight);
            break;
        case LED_MODE_LEFT:
            LedOff(LedRight);
            LedOn(LedLeft);
            rt_thread_mdelay(250);
            LedOff(LedLeft);
            break;
        case LED_MODE_RIGHT:
            LedOff(LedLeft);
            LedOn(LedRight);
            rt_thread_mdelay(250);
            LedOff(LedRight);
            break;
        default:
            LOG_D("mode error\n");
        }
        rt_thread_mdelay(250);
    }
}
void ledmode(int argn, char *argv[])
{
    if(argn<2){
        LOG_W("ledmode #mode");
        return ;
    }
    led_set_mode(atoi(argv[1]));

}
void led_stop_flag(int i)//设置暂停标志的接口
{
    stopFlag=i;
}

/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(ledmode, set led flash mode);
