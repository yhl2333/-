#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "sensor.h"

#define DEVICE_NAME "temp_ds1"//传感器设备的名字

/* 传感器数据显示接口 */
static void sensor_show_data(struct rt_sensor_data *sensor_data)
{
    rt_kprintf("temp:%3d.%dC, timestamp:%5d\n", sensor_data->data.temp/10,     sensor_data->data.temp%10, sensor_data->timestamp);
}

int main()
{
    rt_device_t dev = RT_NULL;
    struct rt_sensor_data data;
    rt_size_t res, i;

    /* 查找系统中的传感器设备 */
    dev = rt_device_find(DEVICE_NAME);
    if (dev == RT_NULL)
    {
        rt_kprintf("Can't find device:%s\n", DEVICE_NAME);
        return -1;
    }

    /* 以轮询且只读模式打开传感器设备 */
    if (rt_device_open(dev, RT_DEVICE_FLAG_RDONLY) != RT_EOK)
    {
        rt_kprintf("open device failed!");
        return -1;
    }

    for (i = 0; i < 5; i++)
    {
        /* 从传感器读取一个数据 */
        res = rt_device_read(dev, 0, &data, 1);
        if (res != 1)
        {
            rt_kprintf("read data failed!size is %d", res);
        }
        else
        {
            sensor_show_data(&data);
        }
        rt_thread_mdelay(1000);
    }
    /* 关闭传感器设备 */
    rt_device_close(dev);
    return 0;
}
