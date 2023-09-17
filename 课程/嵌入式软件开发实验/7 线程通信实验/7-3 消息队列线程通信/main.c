#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "string.h"   //调用C库的strstr()函数

/* 定义蜂鸣器的控制引脚 */
#define BEEP_PIN GET_PIN(A, 5)
/* 定义按键的控制引脚 */
#define KEY1_PIN GET_PIN(A, 0)
#define KEY2_PIN GET_PIN(A, 1)

/*定义消息内容*/
static char msg_key1[] = "key1 is down, please open the beep!";
static char msg_key2[] = "key2 is down, please close the beep!";

/*线程优先级和时间片*/
#define THREAD_PRIORITY      20
#define THREAD_TIMESLICE     5


/*定义消息体的结构*/
struct msg_head{
    int buffLen;
    char *buff;
};
/* 消息队列控制块 */
static struct rt_messagequeue mq;

/*消息队列长度，以字节为单位，注意，一个消息最小为4字节*/
#define MSG_POOL_SIZE 128
/*存放消息的内存。注意：消息队列的长度会比这个内存池小，因为每个消息至少占4字节 */
static char msg_pool[MSG_POOL_SIZE];

ALIGN(RT_ALIGN_SIZE)//线程栈必须系统对齐
static char keyscan_stack[1024];
static struct rt_thread t_keyscan;//线程控制块
/* 按键扫描线程入口函数，此处的入参没有使用，放在这里是为了消除编译告警 */
static void keyscan_entry(void *parameter)
{
    struct msg_head msg;
    /* 把LED灯引脚设置为输出模式 */
    rt_pin_mode(KEY1_PIN, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY2_PIN, PIN_MODE_INPUT_PULLUP);

    while(1)
    {
        if(PIN_LOW == rt_pin_read(KEY1_PIN)){
            rt_thread_mdelay(30);
            if(PIN_LOW == rt_pin_read(KEY1_PIN)){
                LOG_D("keyscan, key1 down");
                msg.buff = msg_key1;
                msg.buffLen = sizeof(msg_key1);
                /* 发送按键消息到消息队列中 */
                rt_mq_send(&mq, &msg, sizeof(msg));
            }
        }
        if(PIN_LOW == rt_pin_read(KEY2_PIN)){
            rt_thread_mdelay(30);
            if(PIN_LOW == rt_pin_read(KEY2_PIN)){
                LOG_D("keyscan, key2 down");
                msg.buff = msg_key2;
                msg.buffLen = sizeof(msg_key2);
                /* 发送按键消息到消息队列中 */
                rt_mq_send(&mq, &msg, sizeof(msg));
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
    struct msg_head msg;
    int i;

    rt_pin_mode(BEEP_PIN, PIN_MODE_OUTPUT);//模式设置
    rt_pin_write(BEEP_PIN, PIN_HIGH);//默认关闭蜂鸣器

    while(1){
        /*从消息队列中接收消息，如果没有消息，线程会被挂起，直到队列有新消息到达*/
        rt_mq_recv(&mq, &msg, sizeof(msg), RT_WAITING_FOREVER);
        for(i=0;i<msg.buffLen;i++)
            rt_kprintf("%c",msg.buff[i]);
        rt_kprintf("\n");
        if(strstr(msg.buff,"open"))//收到打开消息
            rt_pin_write(BEEP_PIN, PIN_LOW);
        if(strstr(msg.buff,"close"))//收到关闭消息
            rt_pin_write(BEEP_PIN, PIN_HIGH);
    }
}
int main(void)
{
    rt_err_t result;

    /* 初始化一个消息队列 */
    result = rt_mq_init(&mq,
                "mqt",
                &msg_pool[0],      /* 队列使用的内存池指向 msg_pool */
                sizeof(struct msg_head),      /* 每个消息的长度 */
                sizeof(msg_pool),  /* 内存池的大小是 msg_pool 的大小 */
                RT_IPC_FLAG_PRIO); /* 优先级大小的方法分配消息 */
    if (result != RT_EOK)
    {
        rt_kprintf("init message queue failed.\n");
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
