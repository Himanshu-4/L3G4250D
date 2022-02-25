#ifndef _SPI_H_
#define _SPI_H_

#include "main.h"
#include<stdint.h>
#include "stm32f411xe.h"

#ifndef OUT_X_L
#define OUT_X_L 0x28
#endif

extern SPI_HandleTypeDef hspi1;

#define onebyte 1
#define time_out 100 // delay for the processor to wait you can use HAL MAX delay

#define READ(x) ((uint8_t)( x | 0x80))
#define WRITE(x) ((uint8_t)(x))
#define READ_DATA(x) ((uint8_t)(x | 0xc0))


///////////// code to read data in the register
void spi_en(void);
void spi_dis(void);

uint8_t  read_reg(uint8_t );
void write_reg(uint8_t , uint8_t );
void read_data(uint8_t * , uint16_t);


#endif