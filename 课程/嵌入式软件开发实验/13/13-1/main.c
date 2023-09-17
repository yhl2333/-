#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <one_wire.h>

one_wire ds18b20 = GET_PIN(B,9);//定义总线引脚
/* 温度读取接口 */
int16_t ds18b20_get_temp(one_wire bus)
{
    uint8_t TL,TH;
    rt_base_t level;
    int value;
    /* 整个通信时序要求很严格，如果线程被调度出CPU，将可能导致时序不对 */
    level = rt_hw_interrupt_disable();    //禁止任务调度
    /* 每次通信都要初始化总线 */ 
    bus_rst(bus);
    if(!bus_ack(bus))
    {
        LOG_D("NO ACK");
        return -1;
}

    bus_write_byte(bus,0xcc); // 跳过ROM
    bus_write_byte(bus,0x44); // 启动温度转换
    rt_hw_interrupt_enable(level);    //通信完成，开启任务调度

    rt_thread_mdelay(800);  //等待转换完成,至少750ms

    /* 再一次准备通信，同样要禁止任务调度，独占CPU */
level = rt_hw_interrupt_disable();    //禁止任务调度
    bus_rst(bus);        //以初始化总线来启动一次通信过程
    if(!bus_ack(bus))
    {
        LOG_D("NO device");
        return -1;
    }
    bus_write_byte(bus,0xcc);   // 跳过ROM
    bus_write_byte(bus,0xbe);   // 发送读取RAM命令
    TL=bus_read_byte(bus); //读第1节字
    TH=bus_read_byte(bus); //读第2节字
    rt_hw_interrupt_enable(level);    //通信完成，开启任务调度
    /* 把读取到的值扩大10000倍，避免浮点运算 */
    value = ((TH<<4)|(TL>>4))*10000 + (TL&0x0f)*625;
    rt_kprintf("%d.%d\n",value/10000, value%10000);
    return 0;
}

int main(void)
{
    while (1){
        ds18b20_get_temp(ds18b20);//每秒钟读1次温度
        rt_thread_mdelay(1000);
    }
    return RT_EOK;
}
