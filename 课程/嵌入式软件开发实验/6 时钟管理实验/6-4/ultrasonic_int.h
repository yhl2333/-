#ifndef APPLICATIONS_ULTRASONIC_INT_H_
#define APPLICATIONS_ULTRASONIC_INT_H_
#include <rtdevice.h>
#include <drv_common.h>
/* 超声波模块的状态定义 */
enum ULTRA_STATE {
    ULTRA_STATE_NULL=0,   //未初始化
    ULTRA_STATE_INIT,    //已初始化
    ULTRA_STATE_TRIG,    //已发送TRIG信号
    ULTRA_STATE_ECHO_S,  //已收到ECHO信号的上升沿
    ULTRA_STATE_ECHO_E,  //已收到ECHO信号的下降沿
    ULTRA_STATE_END      //测量完成状态
};
/*超声波模块结构体定义*/
struct ultr{
    char *name;          /* 模块名字 */
    struct rt_semaphore sem; /* 用于ECHO引脚检测的信号量 */
    rt_base_t trigPin; /* RTIG引脚 */
    rt_base_t echoPin; /* ECHO引脚 */
    rt_int32_t timeout;
    enum ULTRA_STATE state; /* 超声波模块的状态变量 */
    uint32_t dis;   /*测量结果*/
};
void ultr_init(struct ultr* ul);//超声波初始化接口
rt_int32_t ultr_get_distence(struct ultr* ul);//进行一次测量
#endif /* APPLICATIONS_ULTRASONIC_INT_H_ */
