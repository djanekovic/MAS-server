#ifndef OUTPUT_H
#define OUTPUT_H

#include <ff.h>
#include "ov7670.h"

int write_ppm_header(FIL *f);
int write_yuv422(FIL *f, char image[IMAGE_HEIGHT][IMAGE_WIDTH]);

#endif /* OUTPUT_H */
