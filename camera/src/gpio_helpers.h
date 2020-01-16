#ifndef GPIO_HELPERS_H
#define GPIO_HELPERS_H

#include <stdbool.h>

/* GPIO PIN MASKS */

#define GPIO_DIRECTION 0x000007FF

#define D0_MASK 0x00000001
#define D1_MASK D0_MASK << 1
#define D2_MASK D1_MASK << 1
#define D3_MASK D2_MASK << 1
#define D4_MASK D3_MASK << 1
#define D5_MASK D4_MASK << 1
#define D6_MASK D5_MASK << 1
#define D7_MASK D6_MASK << 1
#define PCLK_MASK D7_MASK << 1
#define HREF_MASK PCLK_MASK << 1
#define VSYNC_MASK HREF_MASK << 1

//TOOD: test inline
/*
bool is_VSYNC_up(u32 gpio) { return gpio & VSYNC_MASK; }
bool is_VSYNC_down(u32 gpio) { return !is_VSYNC_up(gpio); }

bool is_HREF_up(u32 gpio) { return gpio & HREF_MASK; }
bool is_HREF_down(u32 gpio) { return !is_HREF_up(gpio); }

bool is_PCLK_up(u32 gpio) { return gpio & PCLK_MASK; }
bool is_PCLK_down(u32 gpio) { return !is_PCLK_up(gpio); }
*/
#define is_VSYNC_up(gpio) ( gpio & VSYNC_MASK )
#define is_VSYNC_down(gpio) ( !is_VSYNC_up(gpio))

#define is_HREF_up(gpio) ( gpio & HREF_MASK)
#define is_HREF_down(gpio) ( !is_HREF_up(gpio))

#define is_PCLK_up(gpio) ( gpio & PCLK_MASK)
#define is_PCLK_down(gpio) ( !is_PCLK_up(gpio))
#define get_data(gpio) (gpio & 0xff)

#endif /* GPIO_HELPERS_H */
