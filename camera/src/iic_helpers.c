#include <xiic_l.h>
#include <unistd.h>
#include "iic_helpers.h"

int WriteOV7670(u8 reg, u8 value)
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

int write_configuration(struct regval_list *rl)
{
	for (int i = 0; rl[i].reg_num == 0xff && rl[i].value == 0xff; i++) {
		WriteOV7670(rl[i].reg_num, rl[i].value);
	}
}
