#include <stdio.h>
#include <xgpio.h>
#include <xiic_l.h>
#include <xparameters.h>
#include "platform.h"

/* GPIO PIN MASKS */

#define GPIO_DIRECTION 0x000007FF

#define D0_MASK 0x00000001
#define D1_MASK D0_MASK << 1
#define D2_MASK D1_MASK << 1
#define D3_MASK D2_MASK << 1
#define D4_MASK D3_MASK << 1
#define D5_MASK D4_MASK << 1
#define D6_MASK D5_MASK << 1
#define D7_MASK D6_MASK << 1
#define PCLK_MASK D7_MASK << 1
#define HREF_MASK PCLK_MASK << 1
#define VSYNC_MASK HREF_MASK << 1

static int write_ov7670(u8 reg, u8 value)
{
	u8 msg_buffer[2] = {reg, value};

	return XIic_Send(XPAR_AXI_IIC_0_BASEADDR, 0x21, msg_buffer, 2, XIIC_STOP);
}

static int read_ov7670(u8 reg)
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

int main(void)
{
	XGpio pmod;
    u8 tmp;

    init_platform();

    int status = XGpio_Initialize(&pmod, 0);
    if (status != XST_SUCCESS) {
    	printf("Error\n");
    	return status;
    }

    XGpio_SetDataDirection(&pmod, 1, GPIO_DIRECTION);

    configure_vga();

    //TODO: is this ok check?
    tmp = read_ov7670(0x73);
    if (tmp != 0xf0) {
    	return 1;
    }



    cleanup_platform();
    return 0;
}
