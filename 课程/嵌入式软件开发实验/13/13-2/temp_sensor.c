#define DBG_TAG "tmp_sensor"
#include <rtdbg.h>
#include <sensor.h>
#include "one_wire.h"//包含任务13-1中的设计的总线头文件，因为此任务要使用其中的接口
#include <rtthread.h>
#include <rtdevice.h>
#include <string.h>
#include "drv_common.h"
#define MODEL_NAME "ds18b20"
#define DS18B20_ERROR -100  //测量值不会是-100
static one_wire ds18b20 = GET_PIN(B,9);

/* DS18B20温度读取接口 */
static rt_uint32_t ds18b20_get_temp(one_wire bus)
{
    uint8_t TL,TH;
    rt_base_t level;
    rt_uint32_t res;

    level = rt_hw_interrupt_disable();    //禁止任务调度
    // 初始化总线
    bus_rst(bus);
    if(!bus_ack(bus))
    {
        LOG_D("NO ACK");
        return DS18B20_ERROR;
    }
    bus_write_byte(bus,0xcc); // 跳过ROM
    bus_write_byte(bus,0x44); // 发送温度转换命令
    rt_hw_interrupt_enable(level);    //1次通信完成，可以开启任务调度

    rt_thread_mdelay(800);  //等待转换完成,至少750ms

    level = rt_hw_interrupt_disable();    //再次启动通信，先禁止任务调度
    bus_rst(bus);        //初始化总线
    if(!bus_ack(bus))
    {
        LOG_D("NO device");
        return DS18B20_ERROR;
    }
    bus_write_byte(bus,0xcc);   // skip rom
    bus_write_byte(bus,0xbe);   // 读取温度命令
    TL=bus_read_byte(bus);
    TH=bus_read_byte(bus);
    rt_hw_interrupt_enable(level);    //开启任务调度
    /* 扩大10000倍，避免浮点操作 */
    res = ((TH<<4)|(TL>>4))*10000 + (TL&0x0f)*625;
    LOG_D("%d  \n", res);
    return res/1000; //保留小数点后一位,SENSOR设备驱动的命令输出默认保留小数点后一位
}

/*sensor设备数据采集接口实现，参数sensor是传感器句柄，buf用于保存读取值的内存首地址，len为内存长度*/
rt_size_t ds18b20_fetch_data(struct rt_sensor_device *sensor, void *buf, rt_size_t len)
{
    LOG_D("ds18b20 fetch data");
    struct rt_sensor_data *data = buf;

    if(sensor->config.mode == RT_SENSOR_MODE_POLLING)//支持轮询方式读到数据
    {
        data->data.temp  = ds18b20_get_temp(ds18b20);
        if(DS18B20_ERROR != data->data.temp){
            data->type = RT_SENSOR_CLASS_TEMP;//类型为温度类型
            data->timestamp = rt_sensor_get_ts();//获取时间戳
            return 1;  //struct rt_sensor_data的个数
        }
    }
    return 0;//表示读取失败
}
/* 设备控制接口的实现，主要实现对sensor设备属性的设置或读取 */
rt_err_t ds18b20_control(struct rt_sensor_device *sensor, int cmd, void *arg)
{
    rt_kprintf("ultr_control %d\n",cmd);
    switch(cmd)
    {
    case RT_SENSOR_CTRL_GET_ID://获取设备ID
        *(char *)arg = 0x01;
        break;
    case RT_SENSOR_CTRL_GET_INFO: //获取设备信息
        memcpy(arg,&sensor->info,sizeof(struct rt_sensor_info));
        rt_kprintf("GET_INFO not suport\n");
        break;
    case RT_SENSOR_CTRL_SET_RANGE: //设备传感器测量范围
        rt_kprintf("SET_RANGE not suport\n");
        break;
    case RT_SENSOR_CTRL_SET_ODR:
        rt_kprintf("SET_ODR not suport\n");
        break;
    case RT_SENSOR_CTRL_SET_MODE:
        sensor->config.mode = *(rt_uint8_t*)arg;
        break;
    case RT_SENSOR_CTRL_SET_POWER:
        rt_kprintf("SET_POWER not suport\n");
        break;
    case RT_SENSOR_CTRL_SELF_TEST:
        rt_kprintf("SELF_TEST not suport\n");
        break;
    }
    return RT_EOK;
}
/*实现传感器操作接口结构体*/
static struct rt_sensor_ops ds18b20_ops =
{
    ds18b20_fetch_data,
    ds18b20_control
};

int  ds18b20_init(void )
{
    int result;
    rt_sensor_t ds18b20_sensor;//定义传感器句柄
    rt_uint32_t flag = RT_DEVICE_FLAG_RDWR;//传感器的标志位，这里设置为可读可写

    /* 分配内存用于存储传感器控制结构 */
    ds18b20_sensor = rt_calloc(1, sizeof(struct rt_sensor_device));
    if (ds18b20_sensor == RT_NULL)
    {
        LOG_E("rt_calloc error\r\n");
        goto __exit;
}
/* 初始化传感器信息 */
    ds18b20_sensor->info.type       = RT_SENSOR_CLASS_TEMP;//类型为温度传感器
    ds18b20_sensor->info.vendor     = RT_SENSOR_VENDOR_UNKNOWN;//厂商未知
    ds18b20_sensor->info.model     =  MODEL_NAME;//设定传感器模块的名字
    ds18b20_sensor->info.unit       = RT_SENSOR_UNIT_DCELSIUS;//单位是摄氏度
    ds18b20_sensor->info.intf_type = RT_SENSOR_INTF_ONEWIRE;//总线是单总线
    ds18b20_sensor->info.range_max = 125;//可测量的最大值，可根据手册设置
    ds18b20_sensor->info.range_min = -50;//可测量的最小值，可根据手册设置
    ds18b20_sensor->info.period_min = 5000;//测量的周期，这里设置为5秒测一次

    ds18b20_sensor->ops = &ds18b20_ops;//初始化传感器操作接口

    /*注册设备，第2个参数为传感器的名字，内核会在给定的名字前加上传感器类型前缀temp_*/ 
    result = rt_hw_sensor_register(ds18b20_sensor, "ds18b20", flag, RT_NULL); 
    if (result != RT_EOK)//检查注册是否成功
    {
        LOG_E("device register err code: %d\r\n", result);
        goto __exit;
    }
    LOG_D("device register %s OK\r\n", DEV_NAME);

    __exit:
    return RT_EOK;
}

/* 导出到板级初始化列表中，这样设备注册在系统启动前期的板级初始化中被执行 */
INIT_BOARD_EXPORT(ds18b20_init);
