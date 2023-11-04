#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "one_line"  //调试信息标签
#define DBG_LVL DBG_LOG     //调试级别定义
#include <rtdbg.h>          //日志头文件
#include "one_wire.h"
void bus_rst(one_wire BUS) //复位时序
{
    rt_pin_mode(BUS, PIN_MODE_OUTPUT);
    rt_pin_write(BUS, PIN_LOW);
    rt_hw_us_delay(750);
    rt_pin_mode(BUS, PIN_MODE_INPUT);//释放总线，此时总线被上拉电阻拉高
}
/* 等待应答时序，返回值为总线是否收到应答，0表示没有等到ACK*/
uint8_t bus_ack(one_wire BUS)
{
    uint8_t retry=0;//重复次数
    /*等待15us后，从机开始发ACK*/
    rt_hw_us_delay(15);
    /*从机ACK 在15~60us后发出，所以这里最多等待100us，如果没有ACK，则直接返回失败*/
    while (rt_pin_read(BUS)&&retry<100)
    {
           retry++;
           rt_hw_us_delay(1);
     };
    if(retry>=100)  return 0; //100us未响应，则判断未检测到
    else retry=0;

     /*此时，从机开始拉低总线60~240 us，需等待从机释放总线（变为高电平），这里最多等待240us*/
    while (!rt_pin_read(BUS)&&retry<240)
    {
            retry++;
            rt_hw_us_delay(1);
    };
    if(retry>=240)  return 0;    //最长拉低240us，超时表示失败
    return 1;//成功
}
/* 写1 bit */
#define write_bit(b)                       \
    do{                                    \
        rt_pin_write(BUS, PIN_LOW);        \
        rt_hw_us_delay(2);                 \
        if(b)                              \
            rt_pin_write(BUS, PIN_HIGH);   \
        rt_hw_us_delay(58);                \
        rt_pin_write(BUS, PIN_HIGH);       \
        rt_hw_us_delay(2);                 \
}while(0)
/* 写1 字节，低位先写 */
void bus_write_byte(one_wire BUS,rt_uint8_t byte)
{
    rt_pin_mode(BUS, PIN_MODE_OUTPUT); // 引脚为输出模式

    for(int i=0;i<8;i++)
    {
        write_bit((byte>>i)&0x01);
    }

    rt_pin_mode(BUS, PIN_MODE_INPUT);         //设置为输入，释放总线

}

/* 读1 bit */
#define read_bit(b)                                    \
    do{                                                \
        rt_pin_mode(BUS, PIN_MODE_OUTPUT);             \
        rt_pin_write(BUS, PIN_LOW);   /*拉低*/         \
        rt_hw_us_delay(2);                             \
        rt_pin_mode(BUS, PIN_MODE_INPUT);/*拉高，释放总线*/ \
        rt_hw_us_delay(10);                             \
        b >>= 1;                                       \
        b |= rt_pin_read(BUS)<<7;                         \
        rt_hw_us_delay(50);                            \
}while(0)
/* 写1 字节，低位先读 */
uint8_t bus_read_byte(one_wire BUS)
{
    uint8_t data=0xff;
    for(int i=0;i<8;i++)
    {
        read_bit(data);
    }
    return data;
}
