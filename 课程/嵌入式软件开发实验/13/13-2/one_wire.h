#ifndef APPLICATIONS_ONE_WIRE_H_
#define APPLICATIONS_ONE_WIRE_H_

/* 定义总线数据类型 */
typedef rt_base_t one_wire;

void bus_rst(one_wire BUS);//复位时序的接口声明
uint8_t bus_ack(one_wire BUS);//等待应答时序的接口声明
void bus_write_byte(one_wire BUS,rt_uint8_t byte);//向总线写1字节的接口声明
uint8_t bus_read_byte(one_wire BUS);//从总线上读1字节的接口声明

#endif /* APPLICATIONS_ONE_WIRE_H_ */
