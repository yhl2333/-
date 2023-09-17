#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include <stdlib.h>   //取绝对值的函数需包含些头文件
#define DBG_TAG "motor"  //日志TAG
#define DBG_LVL DBG_LOG  //日志级别
#include <rtdbg.h>
#include "motor.h"

/*左右电机硬件定义*/
struct car_motor carMotor[MOTOR_ID_NUM]={
        {GET_PIN(B, 13),"pwm4",3,RT_NULL},        /*左电机*/
        {GET_PIN(B, 14),"pwm4",4,RT_NULL}         /*右电机*/
};

/*电机初始化接口，操作电机前必须先初始化*/
int motor_init(void)
{
    int i;
    for(i=0;i<MOTOR_ID_NUM;i++){
        /* 查找设备 */
        carMotor[i].pwmDev =
             (struct rt_device_pwm *)rt_device_find(carMotor[i].deviceName);
        if (carMotor[i].pwmDev == RT_NULL)
        {
            LOG_E("can't find %s !\n", carMotor[i].deviceName);
            return -1;
        }
        rt_pin_mode(carMotor[i].dirPin, PIN_MODE_OUTPUT);
    }
    return RT_EOK;
}

/* 设置电机的方向和速度
 * id:电机的ID
 * speed:电机转速，正负表示转动方向，最大值为100
 */
int motor_speed(enum motor_id id, int speed)
{
    rt_uint32_t period= 500000;//周期为0.5ms（单位为纳秒ns）
rt_uint32_t pulse = 0;//PWM脉冲宽度值，单位为纳秒ns

    if(id >= MOTOR_ID_NUM)
        id = 0;//id错误，默认设置为id=0
    if(speed>100 || speed<-100)
        speed = 100;//转速大于最大值，默认设置为最大值
    pulse = (period/100)*abs(speed);

    /* 设置电机的转动方向 */
    if(speed < 0){
      rt_pin_write(carMotor[id].dirPin, PIN_LOW);
    }
    else if(speed > 0){
      rt_pin_write(carMotor[id].dirPin, PIN_HIGH);
    }
    else {
        rt_pin_write(carMotor[id].dirPin, PIN_LOW);
    }
    /* 设置PWM周期和脉冲宽度默认值 ，并启动电机*/
    if(carMotor[id].pwmDev){
        rt_pwm_set(carMotor[id].pwmDev,
                   carMotor[id].pwmChanel, period, pulse);
        /* 使能设备 */
        rt_pwm_enable(carMotor[id].pwmDev, carMotor[id].pwmChanel);
        return RT_EOK;
    }else {
        LOG_E("motor must init first");
        return RT_ERROR;
    }

}
