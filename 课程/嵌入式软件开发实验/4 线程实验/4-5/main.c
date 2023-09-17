#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

/*LED灯引脚定义*/
#define LedLeft GET_PIN(D, 8)
#define LedRight GET_PIN(D, 9)
/*开/关的定义，使用宏定义的好处是提高代码可读性*/
#define LedOn(pin) rt_pin_write(pin, PIN_LOW)
#define LedOff(pin) rt_pin_write(pin, PIN_HIGH)

void led_flash(void)
{
    int i;
    LedOn(LedLeft);
LedOn(LedRight);
/*以下使用while等待的方法实现延时，注意，不能用rt_thread_delay等函数*/
    i=1<<20;
    while(i--); 
    LedOff(LedLeft);
LedOff(LedRight);
/*使用while等待的方法实现延时，注意，不能用rt_thread_delay等函数*/
    i=1<<20;
    while(i--);
}

int main(void)
{
    rt_pin_mode(LedLeft, PIN_MODE_OUTPUT);
    rt_pin_mode(LedRight, PIN_MODE_OUTPUT);
    /* 设置空闲钩子函数 */
    rt_thread_idle_sethook(led_flash);
    return RT_EOK;
}
