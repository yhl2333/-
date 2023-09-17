#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "BEEP"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#define KeyBeep GET_PIN(A, 0)//按键引脚
#define Beep GET_PIN(A, 5) //蜂鸣器引脚

#define USE_INTERRUPT_CABACK //默认定义此宏，使用中断法，以下任何浅色部分不参与编译

#ifndef USE_INTERRUPT_CABACK
/*扫描法的线程入口函数*/
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
        rt_thread_mdelay(100);//每0.1秒进行一次按键扫描
    }

    return RT_EOK;
}
#else  // USE_INTERRUPT_CABACK，中断法线程入口函数设计。
/*中断法，使用信号量进行线程与中断的同步*/
static struct rt_semaphore key_sem;  /* 信号量定义 */

/* 定义中断回调函数，当产生中断，会进入此回调函数*/
void beep_cb(void *args)
{
    /* 发送信号量唤醒线程 */
    rt_sem_release(&key_sem);
}

/*中断法的线程入口函数*/
void beep_thread_entry()
{
    /* 初始化信号量 */
    rt_sem_init(&key_sem, "key", 0, RT_IPC_FLAG_PRIO);
    /* 把蜂鸣器引脚设置为推拉模式 */
    rt_pin_mode(Beep, PIN_MODE_OUTPUT);
    /* 初始化蜂鸣器默认状态为不响 */
    rt_pin_write(Beep, PIN_HIGH);

    /* 把按键引脚设置为上拉输入模式 */
    rt_pin_mode(KeyBeep, PIN_MODE_INPUT_PULLUP);
    /* 绑定中断，双边沿触发模式，回调函数名为beep_on */
    rt_pin_attach_irq(KeyBeep, PIN_IRQ_MODE_FALLING, beep_cb, RT_NULL);
    /* 使能中断 */
    rt_pin_irq_enable(KeyBeep, PIN_IRQ_ENABLE);

    while(1)
    {
        /* 阻塞等待接收信号量，等到信号量后再次读取数据 */
        rt_sem_take(&key_sem, RT_WAITING_FOREVER);
        if(PIN_LOW==rt_pin_read(KeyBeep))
        {
            rt_thread_mdelay(20);//延时去抖
            if(PIN_LOW==rt_pin_read(KeyBeep)){
                /* 按按键下，驱动蜂鸣器响  */
                rt_pin_write(Beep, PIN_LOW);
                /* 等待按键台起  */
                while(PIN_LOW==rt_pin_read(KeyBeep));
                /* 关闭蜂鸣器  */
                rt_pin_write(Beep, PIN_HIGH);
}
        }
    }
}
#endif  // USE_INTERRUPT_CABACK
