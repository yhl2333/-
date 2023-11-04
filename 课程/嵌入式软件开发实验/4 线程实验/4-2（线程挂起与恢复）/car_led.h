#ifndef APPLICATIONS_CAR_LED_H_
#define APPLICATIONS_CAR_LED_H_
enum led_mode {
    LED_MODE_STOP=0,
    LED_MODE_Double,
    LED_MODE_LEFT,
    LED_MODE_RIGHT
};
void led_thread_entry();
void led_set_mode(enum led_mode m);
void led_stop_flag(int i); //接口声明，同时导出模块接口供其它模块使用
#endif /* APPLICATIONS_CAR_LED_H_ */

