#include "spi.h"

//////////////////////////// enable the chip select line 
void spi_en(void)
{
 HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3 , RESET);
}

////////// disable the spi
void spi_dis(void)
{
HAL_GPIO_WritePin(GPIOE , GPIO_PIN_3 , SET);
}

//// definations of register here 
uint8_t read_reg(uint8_t addr)
{
    addr = READ(addr);
    uint8_t var =0;
    spi_en();
    HAL_SPI_Transmit(&hspi1, &addr, onebyte ,time_out);
    HAL_SPI_Receive(&hspi1, &var, onebyte, time_out);
    spi_dis();
    return var;

}

////////// write register 
void write_reg(uint8_t addr, uint8_t data)
{
    addr = WRITE(addr);
    spi_en();
    HAL_SPI_Transmit(&hspi1 , &addr  , onebyte , time_out);
    HAL_SPI_Transmit(&hspi1, &data, onebyte, time_out);
    spi_dis();

}
void read_data(uint8_t *ptr, uint16_t size)
{
    uint8_t var = READ_DATA(OUT_X_L);
    spi_en();
    HAL_SPI_Transmit(&hspi1 , &var , onebyte , time_out);
    HAL_SPI_Receive(&hspi1 , ptr , size, time_out);
    spi_dis();

}
