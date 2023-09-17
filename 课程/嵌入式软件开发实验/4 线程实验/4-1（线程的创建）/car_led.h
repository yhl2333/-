#ifndef APPLICATIONS_CAR_LED_H_
#define APPLICATIONS_CAR_LED_H_

/* 车灯闪烁模式定义 */
enum led_mode {
    LED_MODE_STOP=0, //停止闪烁
    LED_MODE_Double, //双闪
    LED_MODE_LEFT,   //左灯闪烁
    LED_MODE_RIGHT   //右灯闪烁
};
void led_thread_entry();               //线程入口函数声明
void led_set_mode(enum led_mode m);    //车灯闪烁模式设置声明

#endif /* APPLICATIONS_CAR_LED_H_ */
