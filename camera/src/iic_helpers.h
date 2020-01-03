#ifndef IIC_HELPERS_H
#define IIC_HELPERS_H

int write_ov7670(u8 reg, u8 value);
int read_ov7670(u8 reg);
void configure_vga(void);


#endif /* IIC_HELPERS_H */
