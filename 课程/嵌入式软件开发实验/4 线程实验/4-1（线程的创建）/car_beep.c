#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "BEEP"     //定义日志打印标签
#define DBG_LVL DBG_LOG    //定义日志打印级别
#include <rtdbg.h>         //以上2个宏定义一定要在这个头文件前定义才有效
#define KeyBeep GET_PIN(A, 0)  //按键引脚定义
#define Beep GET_PIN(A, 5)     //蜂鸣器引脚定义
/*按键扫描并控制蜂鸣器的接口实现*/
int beep_thread_entry(void)
{
    /* 把蜂鸣器引脚设置为推拉模式 */
    rt_pin_mode(Beep, PIN_MODE_OUTPUT);
    /* 把按键引脚设置为上拉输入模式 */
    rt_pin_mode(KeyBeep, PIN_MODE_INPUT_PULLUP);

    while (1)
    {
        if(PIN_LOW==rt_pin_read(KeyBeep)){//按键按下
            rt_thread_mdelay(20);//延时去抖
            if(PIN_LOW==rt_pin_read(KeyBeep))
                rt_pin_write(Beep, PIN_LOW);//蜂鸣器响
        }
        else
            rt_pin_write(Beep, PIN_HIGH);//否则，蜂鸣器不响

        rt_thread_mdelay(100);//每0.1秒进行一次按键扫描，线程要有让出CPU的时候
    }

    return RT_EOK;
}

