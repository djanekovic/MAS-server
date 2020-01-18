#ifndef OUTPUT_H
#define OUTPUT_H

#include <ff.h>
#include "ov7670.h"

int write_ppm_header(FIL *f);
int write_888_image(FIL *f, const void *image, size_t width, size_t height);
int write_422_image(FIL *f, const void *image, size_t width, size_t height);

#endif /* OUTPUT_H */
