#include <xil_printf.h>
#include <unistd.h>

#include "ov7670.h"
#include "gpio_helpers.h"
#include "iic_helpers.h"

int init_ov7670(void)
{
	WriteOV7670(0x12, 0x80);
	usleep(5000);
	write_configuration(ov7670_default_regs);
	write_configuration(ov7670_fmt_yuv422);
	WriteOV7670(0x11, 0x1F);

	//xil_printf("U 0x70: 0x%x\n", read_ov7670(0x70));
	//xil_printf("U 0x71: 0x%x\n", read_ov7670(0x71));
	//xil_printf("COM10: 0x%x\n", read_ov7670(REG_COM10));

	return 0;
}

int get_yuv_image(signed char image[IMAGE_HEIGHT * IMAGE_WIDTH * 2], XGpio *pmod)
{
    while(is_VSYNC_down(XGpio_DiscreteRead(pmod, 1)));
    //xil_printf("VSYNC je 1\n");
    while(is_VSYNC_up(XGpio_DiscreteRead(pmod, 1)));

    for (int y = 0; y < IMAGE_HEIGHT; y++){
        while(is_HREF_down(XGpio_DiscreteRead(pmod, 1)));
    	//xil_printf("%d HREF je u jedinici\n", y);
        for (int x = 0; x < IMAGE_WIDTH * 2; x++) {
        	while(is_PCLK_down(XGpio_DiscreteRead(pmod, 1)));

        	if (is_HREF_down(XGpio_DiscreteRead(pmod, 1))) {
        		xil_printf("HREF error\n");
        		return XST_FAILURE;
        	}

        	image[y * IMAGE_WIDTH * 2 + x] = get_data(XGpio_DiscreteRead(pmod, 1));
        	while(is_PCLK_up(XGpio_DiscreteRead(pmod, 1)));
        }
        //xil_printf("Skupio sam cijeli red\n");
    }

    return 0;
}

int get_rgb_image(unsigned char image[IMAGE_HEIGHT * IMAGE_WIDTH * 3], XGpio *pmod)
{
    while(is_VSYNC_down(XGpio_DiscreteRead(pmod, 1)));
    //xil_printf("VSYNC je 1\n");
    while(is_VSYNC_up(XGpio_DiscreteRead(pmod, 1)));

    for (int y = 0; y < IMAGE_HEIGHT; y++){
        while(is_HREF_down(XGpio_DiscreteRead(pmod, 1)));
    	//xil_printf("%d HREF je u jedinici\n", y);
        for (int x = 0; x < IMAGE_WIDTH * 3; x++) {
        	while(is_PCLK_down(XGpio_DiscreteRead(pmod, 1)));

        	if (is_HREF_down(XGpio_DiscreteRead(pmod, 1))) {
        		xil_printf("HREF error\n");
        		return XST_FAILURE;
        	}

        	image[y * IMAGE_WIDTH * 3 + x] = get_data(XGpio_DiscreteRead(pmod, 1));
        	while(is_PCLK_up(XGpio_DiscreteRead(pmod, 1)));
        }
        //xil_printf("Skupio sam cijeli red\n");
    }

    return 0;
}

