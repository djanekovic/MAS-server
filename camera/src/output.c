#include "output.h"

int write_ppm_header(FIL *f)
{
	UINT num_written;
	int status = f_write(f, (const void *) "P5\n", 3, &num_written);
	if (status || num_written != 3) {
		return XST_FAILURE;
	}

	status = f_write(f, (const void *) "640 480\n", 8, &num_written);
	if (status || num_written != 8) {
		return XST_FAILURE;
	}

	status = f_write(f, (const void *) "255\n", 4, &num_written);
	if (status || num_written != 4) {
		return XST_FAILURE;
	}

	return 0;
}

int write_yuv422(FIL *f, char image[IMAGE_HEIGHT][IMAGE_WIDTH])
{
	int status = 0;
	for (int i = 0; i < IMAGE_HEIGHT; i++) {
		UINT num_written;
		status = f_write(f, (const void*) &image[i], IMAGE_WIDTH, &num_written);
		if (status || num_written != IMAGE_WIDTH) {
			return XST_FAILURE;
		}
	}

	return 0;
}
