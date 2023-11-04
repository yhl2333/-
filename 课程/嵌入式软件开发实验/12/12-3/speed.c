#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "speed.h"

/* 中断回调函数，如果B相引脚有上升沿到达，此函数会被执行 */
void call_back(void *args)
{
    struct encoder *ecd = (struct encoder *)args;
    /* 读A相电平值  */
    if(PIN_HIGH == rt_pin_read(ecd->phaseA)){
        /* 如果电平值为高电平，正转，计数加1 */
        ecd->counter++;
    }
    else {
        /* 否则，反转，计数减1*/
        ecd->counter--;
    }
}

void encoder_entry(void * arg)
{
    struct encoder* ecd;
    rt_uint32_t s,e;
    ecd = (struct encoder*)arg;
    while(1){
        s = ecd->counter;//起始记数值
        rt_thread_mdelay(200);
        e = ecd->counter;//结束记数值
        if(e>s)//结束大于起始，一般情况下为正转；但也可能是反转时，发生下溢
            ecd->speed = (e-s > 0x7FFFFFFF)? -(0xFFFFFFFF-e+s+1): (e-s);
        else {//结束小于起始，一般情况下为反转；但也可能是正转时，发生上溢
            ecd->speed = (s-e > 0x7FFFFFFF)? (0xFFFFFFFF-s+e+1): -(s-e);
        }
        ecd->speed = ecd->speed*1000/200;
    }
}

#define THREAD_PRIORITY         20
#define THREAD_STACK_SIZE       512
#define THREAD_TIMESLICE        10
void encoder_init(struct encoder *ecd)
{
    rt_thread_t tid;
    /* 设置引脚模式为输入模式  */
   rt_pin_mode(ecd->phaseA,PIN_MODE_INPUT);
   rt_pin_mode(ecd->phaseB,PIN_MODE_INPUT);
   /* 绑定中断回调函数 */
   rt_pin_attach_irq(ecd->phaseB,PIN_IRQ_MODE_RISING,call_back,ecd);
   rt_pin_irq_enable(ecd->phaseB,PIN_IRQ_ENABLE);//使能中断

   /* 创建线程，名称是 encoder，入口是 encoder_entry*/
   tid = rt_thread_create("encoder",
                           encoder_entry, ecd,
                           THREAD_STACK_SIZE,
                           THREAD_PRIORITY, THREAD_TIMESLICE);
   /* 如果获得线程控制块，启动这个线程 */
   if (tid != RT_NULL)
       rt_thread_startup(tid);
}
