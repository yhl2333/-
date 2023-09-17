#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "car_keyboard.h"

int main(void)
{
    key_init(RT_NULL);
    return RT_EOK;
}
