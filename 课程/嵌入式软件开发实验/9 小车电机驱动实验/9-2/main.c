#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "motor.h"
void stop()//小车停止
{
    motor_speed(MOTOR_ID_LEFT, 0);
    motor_speed(MOTOR_ID_RIGHT, 0);
}
void forward()//小车前进
{
    motor_speed(MOTOR_ID_LEFT, 50);
    motor_speed(MOTOR_ID_RIGHT, 50);
}
void backward()//小车后退
{
    motor_speed(MOTOR_ID_LEFT, -50);
    motor_speed(MOTOR_ID_RIGHT, -50);
}

int main(void)
{
    motor_init();
    forward();
    rt_thread_mdelay(10000);
    stop();
    rt_thread_mdelay(5000);
    backward();
    rt_thread_mdelay(10000);
    stop();
    return RT_EOK;
}
