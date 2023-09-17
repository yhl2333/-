#include <rtthread.h>
#include <rtdevice.h>
#include <drv_common.h>

#define ADC_DEV_NAME        "adc1"  // ADC 设备名称
#define ADC_DEV_CHANNEL     6       // ADC 通道
#define REFER_VOLTAGE 330 //参考电压3.3V,数据精度乘以100保留2位小数
#define CONVERT_BITS 12             //转换位数为12位
rt_adc_device_t adc_dev;            // ADC 设备句柄
rt_uint32_t value;                  // 用于存放读取结果
rt_uint32_t vol;                    // 用于存放计算结果
void voltage_get_value()
{
    /* 查找设备 */
    adc_dev = (rt_adc_device_t)rt_device_find(ADC_DEV_NAME);
    if(RT_NULL == adc_dev)
    {
        rt_kprintf("can not find device %s\n",ADC_DEV_NAME);
        return;
    }
    /* 使能设备 */
    if(RT_EOK != rt_adc_enable(adc_dev, ADC_DEV_CHANNEL))
        return;
    /* 读取采样值 */
    value = rt_adc_read(adc_dev, ADC_DEV_CHANNEL);
    /* 把采用值转换为对应电压值 */
    vol = value * REFER_VOLTAGE/((1UL<<CONVERT_BITS) - 1);
    rt_kprintf("the voltage is :%d.%02d \n", vol/100, vol%100);
    /* 关闭通道 */
    rt_adc_disable(adc_dev, ADC_DEV_CHANNEL);

    return;
}

/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(voltage_get_value, get voltage);
