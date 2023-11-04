#include <rtthread.h>
#include <rtdevice.h>
#include <rtdbg.h>
/* 功能：I2C总线写操作
 * 参数：
 * bus：I2C总线句柄
 * s_addr：从机地址
 * reg:要写入哪个地址
 * data：写入什么数据
 */
rt_err_t I2C_write(struct rt_i2c_bus_device *bus, rt_uint8_t s_addr, rt_uint8_t reg, rt_uint8_t data)
{
    rt_uint8_t buf[2];
    struct rt_i2c_msg msgs;

    buf[0] = reg;
    buf[1] = data;

    msgs.addr = s_addr;
    msgs.flags = RT_I2C_WR;
    msgs.buf = buf;
    msgs.len = 2;

    /* 调用I2C设备接口传输数据 */
    if (rt_i2c_transfer(bus, &msgs, 1) == 1)
    {

        return RT_EOK;
    }
    else
    {
        LOG_E("I2C_write error!");
        return -RT_ERROR;
    }
}

/* 功能：I2C总线读操作
 * 参数：
 * bus：I2C总线句柄
 * s_addr：从机地址
 * reg:要从哪个地址读出
 * data：保存数据的地址指针
 */
rt_err_t I2C_read(struct rt_i2c_bus_device *bus, rt_uint8_t s_addr, rt_int8_t reg, rt_uint8_t *data)
{
    struct rt_i2c_msg msgs[2];
    rt_uint8_t buf[2][2];

    /*写寄存器地址*/
    buf[0][0] = reg; //cmd
    msgs[0].addr = s_addr;
    msgs[0].flags = RT_I2C_WR;
    msgs[0].buf = buf[0];
    msgs[0].len = 1;

    /*读数据*/
    msgs[1].addr = s_addr;
    msgs[1].flags = RT_I2C_RD;
    msgs[1].buf = buf[1];
    msgs[1].len = 1;

    /* 调用I2C设备接口传输数据 */
    if (rt_i2c_transfer(bus, msgs, 2) == 2)
    {
        *data = buf[1][0];
        return RT_EOK;
    }
    else
    {
        LOG_E("I2C_read error!");
        return -RT_ERROR;
    }
}
