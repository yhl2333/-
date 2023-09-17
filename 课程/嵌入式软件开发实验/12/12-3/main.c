#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "speed.h"
struct encoder motorEncoder={
        .phaseA = GET_PIN(D, 12),     // A相引脚
        .phaseB = GET_PIN(D, 13)     // B相引脚
};

int main(void)
{
    encoder_init(&motorEncoder);
    while (1)
    {
        LOG_D("speed=%d",motorEncoder.speed);
        rt_thread_mdelay(1000);
    }
    return RT_EOK;
}
