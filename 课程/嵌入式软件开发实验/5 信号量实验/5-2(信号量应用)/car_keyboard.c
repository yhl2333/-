#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#define DBG_TAG "KEYBOARD"
/*#define DBG_LVL DBG_LOG*/  //如要打输出调试信息，可以打开此宏
#include <rtdbg.h>

#define THREAD_STACK_SIZE   1024
#define THREAD_PRIORITY     19
#define THREAD_TIMESLICE    10

#define ROW_NUM 4  //键盘行数定义
#define COL_NUM 4  //键盘列数定义
/* 键盘行列引脚定义 */
#define ROW_PIN_CONFIG {GET_PIN(E, 12),GET_PIN(E, 13),   \
    GET_PIN(E, 14),GET_PIN(E, 15)                       \
}
#define COL_PIN_CONFIG { GET_PIN(E, 4),GET_PIN(E, 5),  \
    GET_PIN(E, 6),GET_PIN(E, 7)                        \
}
/* 按键值定义 */
#define KEYBOARD_VALUE {  \
    {'1','2','3','A'},    \
    {'4','5','6','B'},    \
    {'7','8','9','C'},    \
    {'0','*','D','E'}     \
}
struct keyboard{
    struct rt_semaphore sem;       //用于中断与线程同步
    void (*key_notice)(char key);  //此接口用于通知用户哪个按键被按下，用户可自行设置此接口
    rt_base_t rowPin[ROW_NUM];     //行引脚定义
    rt_base_t colPin[COL_NUM];     //列引脚定义
    char key[ROW_NUM][COL_NUM];    //键盘键值定义
    char row;                      //当前按键的行ID
    char col;                      //当前按键的列ID
};
/* 默认的键值通知回调函数，此处只是打印出按键的键值 */
void key_notice_default(char key)
{
    rt_kprintf("key: %c\n",key);
}
/*具体键盘定义*/
struct keyboard keyBoard={
    .key_notice = key_notice_default,//通知回调函数，如要需要可能修改这个函数指针
    .rowPin = ROW_PIN_CONFIG,//行引脚定义
    .colPin = COL_PIN_CONFIG, //列引脚定义
    .key = KEYBOARD_VALUE, //按键键值定义
    .row = -1, //当前按键的行值
    .col = -1  //当前按键的列值
};
/* 用于区分不同引脚的中断的变量 */
static char cb_row[]={0,1,2,3};

/* 定义中断回调函数 ，4个引脚使用同一个中断回调函数，使用回调函数的参数来区分不同引脚产生的中断*/
void row_cb(void *iRow)
{

    keyBoard.row = *((char *)iRow);
    LOG_D("row %d",keyBoard.row);
    /* 产生中断，调用此回调函数，然后发送信号量唤醒线程 */
    rt_sem_release(&keyBoard.sem);
}
void key_thread_entry()
{
    int i ;
    int row;
    while(1){
        /* 获取信号量，如果没有按键按下，线程会在这里睡眠 */
        rt_sem_take(&keyBoard.sem, RT_WAITING_FOREVER);
        /* 延时去抖动 */
        rt_thread_mdelay(30);
        row = keyBoard.row;
        /* 再次确定按键已稳定按下， 否则退出此次循环，重新等待按键按下。gRow为产生中断的行序列号 */
        if(rt_pin_read(keyBoard.rowPin[row])==PIN_LOW)
        {
            continue;
        }
        /* 把相应行改成输出，并输出高电平  */
        rt_pin_mode(keyBoard.rowPin[row], PIN_MODE_OUTPUT);
        rt_pin_write(keyBoard.rowPin[row], PIN_HIGH);

        /* 把所有列改为输入，同时读入每个列引脚的值，如果引脚值为高电，说明对应的列有按键按下 */
        for(i=0; i<COL_NUM; i++)
        {
            rt_pin_mode(keyBoard.colPin[i], PIN_MODE_INPUT_PULLDOWN);

            if(PIN_HIGH==rt_pin_read(keyBoard.colPin[i]))//引脚值为高电，说明该列有按键按下
            {
                keyBoard.col = i;//记录列序号
                LOG_D("col=%d",i);
                keyBoard.key_notice(keyBoard.key[row][i]);
                break;
            }
        }

        /* 把列引脚重置为输出高电平 */
        for(i=0;i<COL_NUM;i++)
        {
            /* 把按键引脚设置为上拉输入模式 */
            rt_pin_mode(keyBoard.colPin[i], PIN_MODE_OUTPUT);
            rt_pin_write(keyBoard.colPin[i], PIN_HIGH);
        }

        /* 把行引脚重置为输入 */
        rt_pin_mode(keyBoard.rowPin[row], PIN_MODE_INPUT_PULLDOWN);

        /* 把抖动产生的多余信号量清0 另外，在按键还没台起时，重配置引脚也会再次产生中断*/
        rt_sem_control(&keyBoard.sem, RT_IPC_CMD_RESET, RT_NULL);
        //while(RT_EOK == rt_sem_trytake(&keyBoard.sem));//与上面语句同效
        /*在STM32 HAL库中，尽量不要重复开关中断，会莫名不停产生中断*/
    }
}
void key_init(void (*cb)(char key))
{
    int i;
    rt_thread_t TidKey = RT_NULL;

    if(cb)
        keyBoard.key_notice = cb;
    /* 初始化信号量 */
    rt_sem_init(&keyBoard.sem, "keyboard", 0, RT_IPC_FLAG_PRIO);
    for(i=0;i<COL_NUM;i++)
    {
        /* 把列引脚设置为输出高电平 */
        rt_pin_mode(keyBoard.colPin[i], PIN_MODE_OUTPUT);
        rt_pin_write(keyBoard.colPin[i], PIN_HIGH);
    }

    /* 行引脚设置为下拉输入，上升沿中断模式 */
    for(i=0;i<ROW_NUM;i++)
    {
        /* 把按键引脚设置为下拉输入模式 */
        rt_pin_mode(keyBoard.rowPin[i], PIN_MODE_INPUT_PULLDOWN);
        /* 绑定中断，上升沿触发模式，回调函数名为row_cb */
        rt_pin_attach_irq(keyBoard.rowPin[i], PIN_IRQ_MODE_RISING, row_cb, &cb_row[i]);
    }
    /* 创建矩阵键盘扫描线程 */
    TidKey = rt_thread_create("keyboard",
                                    key_thread_entry,
                                    RT_NULL,
                                    THREAD_STACK_SIZE,
                                    THREAD_PRIORITY,
                                    THREAD_TIMESLICE);
    if (TidKey != RT_NULL)
        rt_thread_startup(TidKey);
    else {
        LOG_D("can not create keyboard thread!");
    }

    /* 使能行引脚中断 */
    for(i=0;i<ROW_NUM;i++)
    {
        rt_pin_irq_enable(keyBoard.rowPin[i], PIN_IRQ_ENABLE);
    }
}
