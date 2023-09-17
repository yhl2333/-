#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "SPEED"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
/* 定义电机方向枚举类型 */
enum motorDir
{
    MOTOR_DIR_STOP=0,     //停止
    MOTOR_DIR_FORWORD,    //正转
    MOTOR_DIR_BACKORD     //反转
};

struct motor_encoder{
    char name[16]; //自定义码盘的名字
    rt_base_t phaseA;   //A相引脚
    rt_base_t phaseB;   //B相引脚
    enum motorDir dir;  //电机方向变量，用于记录电机方向
    rt_sem_t sem;       //信号量，用于中断与线程之前的通信
};

struct motor_encoder encoder_l={
        .name = "ecdr_l",
        .phaseA = GET_PIN(D, 12), /*A相引脚*/
        .phaseB = GET_PIN(D, 13),  /*B相引脚*/
        .sem = RT_NULL
};//左编码盘

/* 中断回调函数，如果B相引脚有上升沿到达，此函数会被执行 */
void call_back(void * arg)
{
    struct motor_encoder* encoder = arg;
    int value = -1;
    /* 读A相电平值 */
    value = rt_pin_read(encoder->phaseA);
    if(PIN_HIGH == value)
        /* 如果电平值为高电平，则方向变量设置为正转 */
        encoder->dir = MOTOR_DIR_FORWORD;
    else {
        /* 否则，方向变量设置为反转 */
        encoder->dir = MOTOR_DIR_BACKORD;
    }
    rt_sem_release(encoder->sem);
}

void motor_encoder_init(struct motor_encoder* encoder)
{

    encoder->sem = rt_sem_create(encoder->name, 0, RT_IPC_FLAG_PRIO);
    /* 设置引脚模式为输入模式  */
    rt_pin_mode(encoder->phaseA,PIN_MODE_INPUT);
    rt_pin_mode(encoder->phaseB,PIN_MODE_INPUT);
    /* 绑定中断回调函数 */
    rt_pin_attach_irq(encoder->phaseB,PIN_IRQ_MODE_RISING,call_back,encoder);

    /* 把方向变量设置为停止，如果有上升沿，中断回调函数会修改此值，所以后面可以通过此变量判断是否有上升沿到达 */
    encoder->dir = MOTOR_DIR_STOP;
}

/* 获取电机方向的函数 */
void motor_encoder_dir(struct motor_encoder* encoder)
{

    if(encoder->sem == RT_NULL)
    {
        LOG_E("please init first");
        return;
}
encoder->dir = MOTOR_DIR_STOP;//先把方向设置为停止
    rt_pin_irq_enable(encoder->phaseB,PIN_IRQ_ENABLE);//使能中断
    /* 等待5秒，如果没有中断，结束等待 */
    rt_sem_take(encoder->sem, 5000);
    /*关闭引脚中断 */
    rt_pin_irq_enable(encoder->phaseB,PIN_IRQ_DISABLE);

    /* 判断方向并打印 */
    switch (encoder->dir){
    case MOTOR_DIR_STOP:
        rt_kprintf("STOP\n");
        break;
    case MOTOR_DIR_FORWORD:
        rt_kprintf("FORWORD\n");
        break;
    case MOTOR_DIR_BACKORD:
        rt_kprintf("BACKWORD\n");
        break;
    default:
        rt_kprintf("ERROR\n");
    }
}

void motor_get_dir()
{
    if(!encoder_l.sem)
        motor_encoder_init(&encoder_l);
    motor_encoder_dir(&encoder_l);
}

/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(motor_get_dir, get motor direction);
