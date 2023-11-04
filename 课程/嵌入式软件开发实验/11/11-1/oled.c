#include <stdlib.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "code_lib.h"  /* 包含字库模块的头文件*/
#include "i2c.h"       /* 包含I2C接口模块的头文件*/
#define OLED_I2C_BUS_NAME          "i2c1"  /* OLED 连接的I2C总线设备名称 */
#define OLED_ADDR                  0x3c    /* I2C总线从设备地址 */

static struct rt_i2c_bus_device *i2c_bus = RT_NULL;
void OLED_WriteCmd(rt_int8_t cmd)
{
    I2C_write(i2c_bus, OLED_ADDR, 0x00, cmd);
}


void OLED_WriteDat(rt_int8_t dat)//写数据
{
    I2C_write(i2c_bus, OLED_ADDR, 0x40, dat);
}

void OLED_Init(void)
{
   //rt_thread_mdelay(100);

   OLED_WriteCmd(0xAE); //关闭显示,开启用AF
   /*内存寻址模式设置，设置为水平寻址*/
   OLED_WriteCmd(0x20); //内存寻址模式设置命令
   OLED_WriteCmd(0x00); //0x00,水平寻址;0x01,垂直;0x02,页寻址 (此为默认模式);其它值无效

   /*页起始地址设置*/
   OLED_WriteCmd(0xb0); //设置页起始地址为0
   /*设置COM扫描方向*/
   OLED_WriteCmd(0xc8);

   /*设置起始列地址*/
   OLED_WriteCmd(0x00); //低4位
   OLED_WriteCmd(0x10); //高4位

   /*设置显示开始行 ,这里的行，是指一行像素点，不是一页，[5:0]设置行数*/
   OLED_WriteCmd(0x40);//从第0行开始显示
   /*设置亮度*/
   OLED_WriteCmd(0x81); //亮度设置命令
   OLED_WriteCmd(0xff); //亮度值

   OLED_WriteCmd(0xa1); //--set segment re-map 0 to 127//段重定义设置,bit0:0,0->0;1,0->127;
   /*设置显示方式*/
   OLED_WriteCmd(0xa6); //bit0决定显示方式，0,正常显示(1亮0灭)，1：反相显示(0亮1灭)
   /*设置复用率（驱动路数），复用率就是用多少行来显示*/
   OLED_WriteCmd(0xa8); //复用率设置命令
   OLED_WriteCmd(0x3F); //复用率值，默认为 0X3F(1/64)

   /*全局显示开启;bit0:1,开启;0,关闭*/
   OLED_WriteCmd(0xa4); //0xa4,按GDDRAM的内容显示;0xa5,忽视GDDRAM内容，直接点亮屏幕
   /*设置显示偏移*/
   OLED_WriteCmd(0xd3); //设置显示偏移命令
   OLED_WriteCmd(0x00); //不偏移，默认为 0
   /*设置时钟分频因子和震荡频率*/
   OLED_WriteCmd(0xd5); //--set display clock divide ratio/oscillator frequency
   OLED_WriteCmd(0xf0); //--set divide ratio[3:0],分频因子;[7:4],震荡频率

   /*设置预充电周期*/
   OLED_WriteCmd(0xd9); //--set pre-charge period
   OLED_WriteCmd(0x22); //; //[3:0],PHASE 1;[7:4],PHASE 2
   /*设置 COM 扫描方向;bit3:0,普通模式;1,重定义模式 COM[N-1]->COM0;N:复用率（驱动路数）*/
   OLED_WriteCmd(0xda); //设置 COM 硬件引脚配置
   OLED_WriteCmd(0x12); //[5:4]配置值

   OLED_WriteCmd(0xdb); //设置 VCOMH 电压倍率
   OLED_WriteCmd(0x20); //0x20,0.77xVcc

   OLED_WriteCmd(0x8d); //设置电荷泵命令
   OLED_WriteCmd(0x14); //开启  bit2，开启/关闭
   OLED_WriteCmd(0xaf); //开启OLED屏幕
}
void OLED_SetPos(unsigned char x, unsigned char y) //设置起始点坐标
{
    OLED_WriteCmd(0xb0+y);//y坐标
    OLED_WriteCmd(((x&0xf0)>>4)|0x10);//x坐标高4位
    OLED_WriteCmd((x&0x0f)|0x01);//x坐标低4位
}
void OLED_Fill(unsigned char fill_Data)//全屏填充
{
    unsigned char m,n;
    for(m=0;m<8;m++)
    {
        OLED_WriteCmd(0xb0+m);       //设置页地址page0-page1
        OLED_WriteCmd(0x00);     //设置列起始地址低4位
        OLED_WriteCmd(0x10);     //设置列起始地址高4位
        for(n=0;n<128;n++)
        {
            OLED_WriteDat(fill_Data);
        }
    }
}

void OLED_CLS(void)//清屏
{
    OLED_Fill(0x00);
}
void OLED_ON(void)
{
    OLED_WriteCmd(0X8D);  //设置电荷泵命令
    OLED_WriteCmd(0X14);  //开启

    OLED_WriteCmd(0XAF);  //OLED唤醒
}

void OLED_OFF(void)
{
    OLED_WriteCmd(0X8D);  //设置电荷泵
    OLED_WriteCmd(0X10);  //关闭

    OLED_WriteCmd(0XAE);  //OLED休眠
}
/*显示一个16*16的汉字
 * x:显示的起始列
 * y：显示的起始页
 * N：显示的汉字在字模数组中的编号，即数组中的第几个汉字
 * */
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N)
{
    unsigned int  col=0;
    for(int row = 0; row < 2; row++){//一个汉字有两页（一页8行）
        OLED_SetPos(x , y+row);//设置起始行和列
        for(col = 0;col < 16;col++)//每行写16字节（一字节一列）
        {
            OLED_WriteDat(F16x16[2*N+row][col]);
        }
    }
}
/*显示一个14*16的汉字*/
void OLED_ShowCN_14(unsigned char x, unsigned char y, unsigned char N)
{
    unsigned int  col=0;
    for(int row = 0; row < 2; row++){//一个汉字有两页（一页8行）
        OLED_SetPos(x , y+row);//设置起始行和列
        for(col = 0;col < 14;col++)//每行写16字节（一字节一列）
        {
            OLED_WriteDat(F14x16[2*N+row][col]);
        }
    }
}
/*显示8*16大小的英文*/
void OLED_ShowEN(unsigned char x, unsigned char y)
{
    int i,j;
    for(i=0;i<9;i++)//9个字节，每个字节占2页（高度是16bit，一页8bit）
    {
        OLED_SetPos(x,y);//设置光标
        for(j=0;j<8;j++)
            OLED_WriteDat(F8x16[i][j]);//显示字节的上半部分
        OLED_SetPos(x,y+1);//光标垂直移动1页
        for(j=0;j<8;j++)
            OLED_WriteDat(F8x16[i][j+8]);//显示字节的下半部分
        x += 8;//水平移动列
    }
}
/*显示全部信息*/
void oled_display()
{
    unsigned char i;
    i2c_bus = (struct rt_i2c_bus_device *)rt_device_find(OLED_I2C_BUS_NAME);

    if (i2c_bus == RT_NULL)
    {
        rt_kprintf("can't find %s device!\n", OLED_I2C_BUS_NAME);
    }
    OLED_Init();
    OLED_Fill(0xFF);//全屏点亮
    OLED_Fill(0x00);//全屏灭
    for(i=0;i<4;i++)
    {
        OLED_ShowCN(8+2*i*16,2,i);//显示16*16中文：欢迎使用
    }
    OLED_ShowEN(0,4);//显示英文字母：RT-Thread
    for(i=0;i<4;i++)
    {
        OLED_ShowCN_14(72+i*14,4,i);//显示14*16中文：智能小车
    }
}
/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(oled_display, OLED display );
