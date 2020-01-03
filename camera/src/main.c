#include <stdio.h>
#include <xgpio.h>
#include <xparameters.h>

#include "platform.h"
#include "gpio_helpers.h"
#include "iic_helpers.h"

int main(void)
{
	XGpio pmod;
    u8 tmp;

    init_platform();

    int status = XGpio_Initialize(&pmod, 0);
    if (status != XST_SUCCESS) {
    	printf("Error\n");
    	return status;
    }

    XGpio_SetDataDirection(&pmod, 1, GPIO_DIRECTION);

    configure_vga();

    //TODO: is this ok check?
    tmp = read_ov7670(0x73);
    if (tmp != 0xf0) {
    	return 1;
    }

    cleanup_platform();
    return 0;
}
