#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
//#define AIN1 GET_PIN(B, 13)
#define BIN1 GET_PIN(B, 14)


int main(void)
{
    //rt_pin_mode(AIN1, PIN_MODE_OUTPUT);//设置引脚模式
    rt_pin_mode(BIN1, PIN_MODE_OUTPUT);
    //rt_pin_write(AIN1, PIN_LOW);//设置车轮转动方向
    rt_pin_write(BIN1, PIN_LOW);



    return RT_EOK;
}

void fwd()
{
    //rt_pin_write(AIN1, PIN_HIGH);
    rt_pin_write(BIN1, PIN_LOW);
}

void bwd()
{
    //rt_pin_write(AIN1, PIN_LOW);
    rt_pin_write(BIN1, PIN_HIGH);
}

MSH_CMD_EXPORT(fwd,FWD)
MSH_CMD_EXPORT(bwd,bwd)
