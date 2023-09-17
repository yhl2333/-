#include <rtthread.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "ultrasonic.h"

int main(void)
{
    rt_uint32_t dist;//用于存储测量到的距离值
    rt_int32_t interval=1000;

    ultr_init(&interval);//调用超声波模块初始化函数进行模块初始化

    while (1)
    {
        /* 获取超声波测量结果，如果测量没有完成，这接口会阻塞 */
        dist = ultr_get_distence();
        /* 向串口打印测量结果 */
        rt_kprintf("distence is:%u mm\n",dist);
    }
    return RT_EOK;
}
