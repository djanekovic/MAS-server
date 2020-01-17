#ifndef OV7670_H
#define OV7670_h

#include <xgpio.h>

#define IMAGE_HEIGHT 480
#define IMAGE_WIDTH 1280

int get_yuv_image(char image[IMAGE_HEIGHT][IMAGE_WIDTH], XGpio *pmod);
int init_ov7670(void);

#endif
