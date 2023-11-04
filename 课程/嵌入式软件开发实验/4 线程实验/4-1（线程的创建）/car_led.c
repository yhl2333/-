#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"

#define DBG_TAG "LED"    //定义日志打印标签
#define DBG_LVL DBG_LOG  //定义日志打印级别
/* 包含日志打印头文件。注意，以上2个宏定义一定要在这个头文件前定义才有效*/
#include <rtdbg.h> 
#include <stdlib.h>      //atoi()函数需要包含的头文件
#include "car_led.h"
/* 定义左右转向灯的控制引脚 */
#define LedLeft GET_PIN(D, 8)
#define LedRight GET_PIN(D, 9)
/* 定义开灯/关灯接口 */
#define LedOn(pin) rt_pin_write(pin, PIN_LOW)
#define LedOff(pin) rt_pin_write(pin, PIN_HIGH)

enum led_mode LedMod=LED_MODE_STOP; //车灯默认为不闪烁

/* 设置闪灯模式的接口 */
void led_set_mode(enum led_mode m)   
{
    LedMod = m;
}

/* 车灯控制线程入口函数定义 */
void led_thread_entry()
{
    /*设置车灯控制引脚模式为输出模式*/
    rt_pin_mode(LedLeft, PIN_MODE_OUTPUT);
    rt_pin_mode(LedRight, PIN_MODE_OUTPUT);
    while(1){
        switch(LedMod)//判断模式
        {
        case LED_MODE_STOP://停止闪烁
            LedOff(LedLeft);
            LedOff(LedRight);
            break;
        case LED_MODE_Double://双闪
            LedOn(LedLeft);
            LedOn(LedRight);
            rt_thread_mdelay(500);
            LedOff(LedLeft);
            LedOff(LedRight);
            break;
        case LED_MODE_LEFT://左灯闪
            LedOff(LedRight);
            LedOn(LedLeft);
            rt_thread_mdelay(250);
            LedOff(LedLeft);
            break;
        case LED_MODE_RIGHT://右灯闪
            LedOff(LedLeft);
            LedOn(LedRight);
            rt_thread_mdelay(250);
            LedOff(LedRight);
            break;
        default:
            LOG_D("mode error\n");
        }
        rt_thread_mdelay(250);//此处延时主要是为了让出CPU，不能让线程一直占用CPU
    }
}
/*msh命令接口*/
void ledmode(int argn, char *argv[])
{
    if(argn<2){
        LOG_W("ledmode #mode");
        return ;
    }
    led_set_mode(atoi(argv[1]));//通过atoi函数把字符变量转为整型变量
}
/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(ledmode, set led flash mode);
