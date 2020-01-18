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


static int _write_image(FIL *f, const void *image, size_t width, size_t height, size_t pixel_size)
{
	int status = 0;
	for (int i = 0; i < height; i++) {
		UINT num_written;
		status = f_write(f, image + (i * width * pixel_size), width * pixel_size, &num_written);
		if (status || num_written != width * pixel_size) {
			return XST_FAILURE;
		}
	}

	return 0;
}


int write_422_image(FIL *f, const void *image, size_t width, size_t height)
{
	return _write_image(f, image, width, height, 2);
}

int write_888_image(FIL *f, const void *image, size_t width, size_t height)
{
	return _write_image(f, image, width, height, 3);
}


