#include <stdlib.h>
#include <assert.h>
#include <ff.h>

struct yuv_image {
    signed char *y;
    signed char *u;
    signed char *v;
};

#define YUV444_INPUT 1
#define TJE_IMPLEMENTATION
#include "jpeg.h"

static void init_yuv_image(struct yuv_image *image, int width, int height)
{
    image->y = malloc(width * height * sizeof(int8_t)); assert(image->y);
    image->u = malloc(width * height * sizeof(int8_t)); assert(image->u);
    image->v = malloc(width * height * sizeof(int8_t)); assert(image->v);
}

static void my_write(void *ctx, void *data, int size)
{
	FIL *f = (FIL *) ctx;

	UINT num_written;
	int status = f_write(f, data, size, &num_written);
	if (status || (num_written != size)) {
		xil_printf("Upis nije dobro prosao, problem u callbacku.");
	}
}


int generate_jpeg(FIL *f, const signed char *raw_image, int width, int height)
{
	struct yuv_image image;
    init_yuv_image(&image, 640, 480);

    for (int i = 0; i < 480; i++) {
        unsigned char row_buffer[2 * 640];
        memcpy(row_buffer, &raw_image[i], 2 * width);

        // 422 YUYV upsampling u 444
        for (int j = 0, y_index = 0; j < 2 * 640; j += 4) {
            unsigned char y0, y1, u0, v0;
            y0 = row_buffer[j + 0];  u0 = row_buffer[j + 1];
            y1 = row_buffer[j + 2];  v0 = row_buffer[j + 3];

            image.y[i * 640 + y_index] = y0;
            image.u[i * 640 + y_index] = u0;
            image.v[i * 640 + y_index] = v0;

            y_index++;
            image.y[i * 640 + y_index] = y1;
            image.u[i * 640 + y_index] = u0;
            image.v[i * 640 + y_index] = v0;
            y_index++;
        }
    }

    int result = tje_encode_with_func(my_write, f, 1, width, height, 3, &image);
    if (result) {
    	return 0;
    }

	return 1;
}
