#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ff.h>
#include <xil_printf.h>
#include <xgpio.h>
#include <xparameters.h>

#include "platform.h"
#include "ov7670.h"
#include "output.h"
#include "gpio_helpers.h"
#include "iic_helpers.h"
#include "jpeg.h"

#define JPEG 0

int main(void)
{
	FIL f;
	FATFS fatfs;
	BYTE work[FF_MAX_SS];
	XGpio pmod;

#if JPEG
	const char *filename = "slika.jpg";
#else
	const char *filename = "slika.bin";
#endif

    signed char image[IMAGE_HEIGHT * IMAGE_WIDTH * 3];

    memset(image, 0, IMAGE_HEIGHT * IMAGE_WIDTH * 3);

    init_platform();
    int status = init_gpio(&pmod);
    status = init_fs(&fatfs, work, FF_MAX_SS);
    if (status) {
    	xil_printf("Init_fs failed.");
    	return XST_FAILURE;
    }

    status = f_open(&f, filename, FA_CREATE_ALWAYS | FA_WRITE);
    if (status) {
    	return XST_FAILURE;
    }

	status = f_lseek(&f, 0);
	if (status) {
		return XST_FAILURE;
	}

	status = init_ov7670();
	WriteOV7670(REG_MVFP, 0x30);
	//WriteOV7670(REG_TSLB, 0x04);
	//WriteOV7670(0x9f, 0xF0);
	//WriteOV7670(0xa0, 0xC0);

	if (status) {
		xil_printf("ov7670 init routine failed, exiting...\n");
		return XST_FAILURE;
	}

    xil_printf("Pocinjem citati sliku\n");

    status = get_yuv_image(image, &pmod);
    if (status) {
    	xil_printf("Reading image failed\n");
    	return status;
    }

#if JPEG
    xil_printf("Pocinjem raditi JPEG kompresiju.\n");
    status = generate_jpeg(&f, image, IMAGE_WIDTH, IMAGE_HEIGHT);
    if (status) {
    	xil_printf("JPEG routine failed");
    	return status;
    }

#else
    xil_printf("Zapisivanje raw filea\n");

    status = write_422_image(&f, image, IMAGE_WIDTH, IMAGE_HEIGHT);
    if (status) {
    	xil_printf("Writing to SD card failed\n");
    	return status;
    }
#endif
    f_close(&f);

    xil_printf("Gotov\n");

    cleanup_platform();
    return 0;
}
