#include <unistd.h>
#include <stdlib.h>
#include <ff.h>
#include <xil_printf.h>
#include <xgpio.h>
#include <xparameters.h>

#include "platform.h"
#include "gpio_helpers.h"
#include "iic_helpers.h"


int main(void)
{
	FIL f;
	FATFS fatfs;
	BYTE work[FF_MAX_SS];
	XGpio pmod;
    u8 image[480][1280];

    init_platform();


    int status = XGpio_Initialize(&pmod, 0);
    if (status != XST_SUCCESS) {
    	xil_printf("Error\n");
    	return status;
    }

	status = f_mount(&fatfs, "0:/", 0);
	if (status != FR_OK) {
		return XST_FAILURE;
	}

	status = f_mkfs("0:/", FM_FAT32, 0, work, sizeof work);
	if (status != FR_OK) {
		return XST_FAILURE;
	}

    status = f_open(&f, "slika.pgm", FA_CREATE_ALWAYS | FA_WRITE);
    if (status) {
    	return XST_FAILURE;
    }

	status = f_lseek(&f, 0);
	if (status) {
		return XST_FAILURE;
	}

    XGpio_SetDataDirection(&pmod, 1, GPIO_DIRECTION);

    WriteOV7670(0x12, 0x80);
    usleep(5000);
    write_configuration(ov7670_default_regs);
    write_configuration(ov7670_fmt_yuv422);
    WriteOV7670(0x11, 0x1F);

    xil_printf("U 0x70: 0x%x\n", read_ov7670(0x70));
    xil_printf("U 0x71: 0x%x\n", read_ov7670(0x71));
    xil_printf("COM10: 0x%x\n", read_ov7670(REG_COM10));

    xil_printf("Pocinjem citati sliku\n");


    while(is_VSYNC_down(XGpio_DiscreteRead(&pmod, 1)));
    //xil_printf("VSYNC je 1\n");
    while(is_VSYNC_up(XGpio_DiscreteRead(&pmod, 1)));

    for (int y = 0; y < 480; y++){
        while(is_HREF_down(XGpio_DiscreteRead(&pmod, 1)));
    	//xil_printf("%d HREF je u jedinici\n", y);
        for (int x = 0, z = 0; x < 1280; x++) {
        	while(is_PCLK_down(XGpio_DiscreteRead(&pmod, 1)));

        	if (is_HREF_down(XGpio_DiscreteRead(&pmod, 1))) {
        		xil_printf("HREF error\n");
        		return XST_FAILURE;
        	}
        	if (x % 2 == 0) {
        		image[y][z++] = (XGpio_DiscreteRead(&pmod, 1) & 0xff);
        	}
        	while(is_PCLK_up(XGpio_DiscreteRead(&pmod, 1)));
        }
        //xil_printf("Skupio sam cijeli red\n");
    }

    xil_printf("Zapisivanje filea\n");
    UINT ignore;
    status = f_write(&f, (const void *) "P5\n", 3, &ignore);
    if (status) {
    	return XST_FAILURE;
    }

    status = f_write(&f, (const void *) "640 480\n", 8, &ignore);
    if (status) {
    	return XST_FAILURE;
    }

    status = f_write(&f, (const void *) "255\n", 4, &ignore);
    if (status) {
    	return XST_FAILURE;
    }
    for (int i = 0; i < 480; i++) {
    	UINT n;
    	status = f_write(&f, (const void*) &image[i], 640, &n);
    	if (status && n != 640) {
    		return XST_FAILURE;
    	}
    }

    f_close(&f);

    xil_printf("Gotov\n");

    cleanup_platform();
    return 0;
}
