#include <unistd.h>
#include <stdlib.h>
#include <ff.h>
#include <xil_printf.h>
#include <xgpio.h>
#include <xparameters.h>

#include "platform.h"
#include "ov7670.h"
#include "gpio_helpers.h"
#include "iic_helpers.h"

int main(void)
{
	FIL f;
	FATFS fatfs;
	BYTE work[FF_MAX_SS];
	XGpio pmod;
    char image[IMAGE_HEIGHT][IMAGE_WIDTH];

    init_platform();
    int status = init_gpio(&pmod);
    status = init_fs(&fatfs, work, FF_MAX_SS);

    status = f_open(&f, "slika.pgm", FA_CREATE_ALWAYS | FA_WRITE);
    if (status) {
    	return XST_FAILURE;
    }

	status = f_lseek(&f, 0);
	if (status) {
		return XST_FAILURE;
	}

	status = init_ov7670();
	if (status) {
		xil_printf("ov7670 init routine failed, exiting...\n");
		return XST_FAILURE;
	}

    xil_printf("Pocinjem citati sliku\n");

    status = get_image(image, &pmod);
    if (status) {
    	xil_printf("Reading image failed\n");
    	return status;
    }

    xil_printf("Zapisivanje filea\n");

    status = write_yuv422(&f, image);
    if (status) {
    	xil_printf("Writing to SD card failed\n");
    	return status;
    }

    f_close(&f);

    xil_printf("Gotov\n");

    cleanup_platform();
    return 0;
}
