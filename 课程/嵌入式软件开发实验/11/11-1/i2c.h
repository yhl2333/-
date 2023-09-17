#ifndef APPLICATIONS_I2C_H_
#define APPLICATIONS_I2C_H_
rt_err_t I2C_write(struct rt_i2c_bus_device *bus, rt_uint8_t s_addr, rt_uint8_t reg, rt_uint8_t data);
rt_err_t I2C_read(struct rt_i2c_bus_device *bus, rt_uint8_t s_addr, rt_int8_t reg, rt_uint8_t *data);
#endif /* APPLICATIONS_I2C_H_ */
