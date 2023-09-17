#include <infrared.h>  //包含软件包的头文件

/* 定义变量，用于保存读取到的数据 */
struct infrared_decoder_data infrared_data;

/* 从红外接收头读取数据 */
int infrared_test(void)
{
    ir_select_decoder("nec");  //设置使用NEC协议进行解调
    while (1)
    {
        /* 读取数据 */
        if (infrared_read("nec", &infrared_data) == RT_EOK)
        {
            if (infrared_data.data.nec.repeat)
            {
                /* 如果按键被长按，可以识别为重复按键 */
                rt_kprintf("repeat%d\n", infrared_data.data.nec.repeat);
            }
            else
            {
                /* 打印通信地址和按键的键值 */
                rt_kprintf("APP addr:0x%02X key:0x%02X\n", infrared_data.data.nec.addr, infrared_data.data.nec.key);
            }
        }
        rt_thread_mdelay(10);
    }

    return RT_EOK;
}
/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(infrared_test, infrared receive test);
