#ifndef APPLICATIONS_SPEED_H_
#define APPLICATIONS_SPEED_H_
struct encoder{
    rt_base_t phaseA;//A相引脚
    rt_base_t phaseB;//B相引脚
    rt_uint32_t counter;//脉冲计数
    rt_int32_t speed;//速度
};
void encoder_init(struct encoder *ecd);

#endif /* APPLICATIONS_SPEED_H_ */
