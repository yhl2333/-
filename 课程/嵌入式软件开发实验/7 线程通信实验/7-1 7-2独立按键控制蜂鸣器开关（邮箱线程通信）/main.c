#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

/*如果使用邮箱发送字符串，打开以下宏定义*/
/*#define USE_MB_SEND_STRING*/

#ifdef USE_MB_SEND_STRING
#include "string.h"   //调用C库的strstr()函数
#endif

/* 定义蜂鸣器的控制引脚 */
#define BEEP_PIN GET_PIN(A, 5)
/* 定义按键的控制引脚 */
#define KEY1_PIN GET_PIN(A, 0)
#define KEY2_PIN GET_PIN(A, 1)
#ifdef USE_MB_SEND_STRING
/*定义邮箱消息*/
static char mb_key1[] = "key1 is down, please open the beep!";
static char mb_key2[] = "key2 is down, please close the beep!";

/*定义消息体的结构*/
struct msg_head{
    int buffLen;
    char *buff;
};
static struct msg_head msg1={
        .buffLen = sizeof(mb_key1),
        .buff = mb_key1
};
static struct msg_head msg2={
        .buffLen = sizeof(mb_key2),
        .buff = mb_key2
};
#else
/*定义按键命令值*/
enum beep_cmd{
    BEEP_CMD_OPEN = 0,
    BEEP_CMD_CLOSE
};
#endif

/*线程优先级和时间片*/
#define THREAD_PRIORITY      20
#define THREAD_TIMESLICE     5

/* 邮箱控制块 */
static struct rt_mailbox mb;
/* 用于放邮件的内存池，由于每封邮件大小为4字节，此处32字节只能存8封邮件*/
static char mb_pool[32];
ALIGN(RT_ALIGN_SIZE)//线程栈必须系统对齐
static char keyscan_stack[1024];
static struct rt_thread t_keyscan;//线程控制块

/* 按键扫描线程入口函数，此处的入参没有使用，放在这里是为了消除编译告警 */
static void keyscan_entry(void *parameter)
{
    /* 把LED灯引脚设置为输出模式 */
    rt_pin_mode(KEY1_PIN, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY2_PIN, PIN_MODE_INPUT_PULLUP);

    while(1)
    {
        if(PIN_LOW == rt_pin_read(KEY1_PIN)){
            rt_thread_mdelay(30);
            if(PIN_LOW == rt_pin_read(KEY1_PIN)){
                LOG_D("keyscan, key1 down");
                /* 发送 mb_key1 地址到邮箱中 */
#ifdef USE_MB_SEND_STRING
                /* 发送 mb_key1 地址到邮箱中 */
                rt_mb_send(&mb, (rt_ubase_t)&msg1);
#else
                /* 发送 命令值 到邮箱中 */
                rt_mb_send(&mb, BEEP_CMD_OPEN);
#endif

            }
        }
        if(PIN_LOW == rt_pin_read(KEY2_PIN)){
            rt_thread_mdelay(30);
            if(PIN_LOW == rt_pin_read(KEY2_PIN)){
                LOG_D("keyscan, key2 down");
#ifdef USE_MB_SEND_STRING
                /* 发送 mb_key2 地址到邮箱中 */
                rt_mb_send(&mb, (rt_ubase_t)&msg2);
#else
                /* 发送 命令值 到邮箱中 */
                rt_mb_send(&mb, BEEP_CMD_CLOSE);
#endif

            }
        }
        rt_thread_mdelay(100);//0.1秒扫描一次按键
    }

}
ALIGN(RT_ALIGN_SIZE)
static char beepctl_stack[1024];
static struct rt_thread t_beepctl;

/* 蜂鸣器控制线程入口函数 */
static void beepctl_entry(void *parameter)
{
    rt_ubase_t value;
#ifdef USE_MB_SEND_STRING
    struct msg_head *msg;
#endif
    rt_pin_mode(BEEP_PIN, PIN_MODE_OUTPUT);//模式设置
    rt_pin_write(BEEP_PIN, PIN_HIGH);//默认关闭蜂鸣器

    while(1){
        /*从邮箱接收邮件，如果没有邮件，线程会被挂起，直到邮件有新邮件到达*/
        rt_mb_recv(&mb, &value, RT_WAITING_FOREVER);
#ifdef USE_MB_SEND_STRING
        msg = (struct msg_head *)value;
        LOG_D("beepctl,receive mail %s",msg->buff);
        if(strstr(msg->buff,"open"))//收到打开消息
            rt_pin_write(BEEP_PIN, PIN_LOW);
        if(strstr(msg->buff,"close"))//收到关闭消息
            rt_pin_write(BEEP_PIN, PIN_HIGH);
#else
        LOG_D("beepctl,receive cmd %s",value? " CLOSE":"OPEN");
        switch(value)//判断邮件内容
        {
        case BEEP_CMD_OPEN://收到打开蜂鸣器的命令
            rt_pin_write(BEEP_PIN, PIN_LOW);
            break;
        case BEEP_CMD_CLOSE: //收到关闭蜂鸣器的命令
            rt_pin_write(BEEP_PIN, PIN_HIGH);
            break;
        default:
            break;
        }

#endif
    }
}
int main(void)
{
    rt_err_t result;

    /* 初始化一个邮箱 */
    result = rt_mb_init(&mb,
                        "mbt",         /* 名称是 mbt */
                        &mb_pool[0],  /* 邮箱用到的内存池是 mb_pool */
                        sizeof(mb_pool)/4, /* 邮箱中的邮件数目，一封邮件4字节 */
                        RT_IPC_FLAG_FIFO); /* 采用 FIFO 方式进行线程等待 */
    if (result != RT_EOK)
    {
        rt_kprintf("init mailbox failed.\n");
        return -1;
}

    /*以下为创建和启动线程*/
    rt_thread_init(&t_keyscan,
                   "keyscan",
                   keyscan_entry,
                   RT_NULL,
                   &keyscan_stack[0],
                   sizeof(keyscan_stack),
                   THREAD_PRIORITY, THREAD_TIMESLICE);
    rt_thread_startup(&t_keyscan);

    rt_thread_init(&t_beepctl,
                   "beepctl",
                   beepctl_entry,
                   RT_NULL,
                   &beepctl_stack[0],
                   sizeof(beepctl_stack),
                   THREAD_PRIORITY, THREAD_TIMESLICE);
    rt_thread_startup(&t_beepctl);
    return 0;
}
