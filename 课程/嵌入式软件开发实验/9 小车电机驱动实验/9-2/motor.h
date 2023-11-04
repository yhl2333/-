#ifndef APPLICATIONS_MOTOR_H_
#define APPLICATIONS_MOTOR_H_
/*电机ID定义*/
enum motor_id{
    MOTOR_ID_LEFT=0,
    MOTOR_ID_RIGHT,
    MOTOR_ID_NUM
};
#define DEVICE_NAME_LEN 16  //pwm设备名字的长度
struct car_motor{
    rt_base_t dirPin;                 //电机方向控制引脚
    char deviceName[DEVICE_NAME_LEN]; //驱动电机的PWM设备名称
    char pwmChanel;                   //驱动电机的PWM通道
    struct rt_device_pwm *pwmDev;    //PWM设备句柄 ，初始化后才得到句柄
};

/*电机初始化接口，操作电机前必须先初始化*/
int motor_init(void);
/*设置电机的方向和速度*/
int motor_speed(enum motor_id id, int speed);
#endif /* APPLICATIONS_MOTOR_H_ */
