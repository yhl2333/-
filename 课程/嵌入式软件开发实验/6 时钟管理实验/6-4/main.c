#include <rtthread.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "ultrasonic_int.h"

#define MODULE_NAME "hcsr04"
int main(void)
{
    struct ultr hcsr04={
        .name = MODULE_NAME,
        .echoPin = GET_PIN(B, 1), /* RTIG引脚定义*/
        .trigPin = GET_PIN(B, 0),  /* ECHO引脚定义 */
        .timeout = 1000
    };
    ultr_init(&hcsr04);
    while (1)
    {
        ultr_get_distence(&hcsr04);
        rt_thread_mdelay(1000);
    }
    return RT_EOK;
}
