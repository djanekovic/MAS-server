#include <xiic_l.h>
#include "iic_helpers.h"

int write_ov7670(u8 reg, u8 value)
{
	u8 msg_buffer[2] = {reg, value};

	return XIic_Send(XPAR_AXI_IIC_0_BASEADDR, 0x21, msg_buffer, 2, XIIC_STOP);
}

int read_ov7670(u8 reg)
{
	u8 msg_buffer[1] = {reg};

	// send target reg and then get byte
	XIic_Send(XPAR_AXI_IIC_0_BASEADDR, 0x21, msg_buffer, 1, XIIC_STOP);
	XIic_Recv(XPAR_AXI_IIC_0_BASEADDR, 0x21, msg_buffer, 1, XIIC_STOP);

	return msg_buffer[0];
}


void configure_vga(void)
{
	// docs table 2.2

	write_ov7670(0x11, 0x01);
	write_ov7670(0x12, 0x00);
	write_ov7670(0x0c, 0x00);
	write_ov7670(0x3e, 0x00);
	write_ov7670(0x70, 0x3a);
	write_ov7670(0x71, 0x35);
	write_ov7670(0x72, 0x11);
	write_ov7670(0x73, 0xf0);
	write_ov7670(0xa2, 0x02);

	return;
}
