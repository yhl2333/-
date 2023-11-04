#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "SPEED"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

/* B相引脚定义 */
#define MOTOR_PHASE_B GET_PIN(D, 13)
/* 定义编码器分辨率 */
#define CODER_RESOLUTION 16
/* 脉冲计算变量，初始化为0 ，volatile保证读取变量时，取到最新值 */
static volatile rt_int32_t pulseCount = 0;

/* 测速情况下的中断回调函数，如果B相引脚有上升沿到达，此函数会被执行 */
void speek_cb()
{
    pulseCount++;
}

/* 采用M法获取电机转速的函数 */
void motor_get_speed(void)
{
    int speed;
    pulseCount = 0;//清0计数
    /* 设置引脚模式为输入模式  */
    rt_pin_mode(MOTOR_PHASE_B,PIN_MODE_INPUT);
    /* 绑定中断回调函数 */
    rt_pin_attach_irq(MOTOR_PHASE_B,PIN_IRQ_MODE_RISING,speek_cb,RT_NULL);

    rt_pin_irq_enable(MOTOR_PHASE_B,PIN_IRQ_ENABLE);//使能中断
    rt_thread_mdelay(1000);
    /*解绑定回调函数 */
    rt_pin_detach_irq(MOTOR_PHASE_B);
    /*关闭引脚中断 */
    rt_pin_irq_enable(MOTOR_PHASE_B,PIN_IRQ_DISABLE);
    speed = pulseCount/CODER_RESOLUTION;
    rt_kprintf("motor speed is %d r/s\n",speed);
}
MSH_CMD_EXPORT(motor_get_speed, get motor speed);
