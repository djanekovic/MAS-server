#ifndef OV7670_H
#define OV7670_h

#include <xgpio.h>

#define IMAGE_HEIGHT 480
#define IMAGE_WIDTH 640

int get_yuv_image(signed char image[IMAGE_HEIGHT * IMAGE_WIDTH * 2], XGpio *pmod);
int get_rgb_image(unsigned char image[IMAGE_HEIGHT * IMAGE_WIDTH * 3], XGpio *pmod);
int init_ov7670(void);

#endif
