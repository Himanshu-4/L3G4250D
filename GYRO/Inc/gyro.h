
#ifndef _GYRO_H_
#define _GYRO_H_

#include <stdint.h>
#include "l3g4reg.h"
#include "spi.h"
//////////////// decription of srtucture here
#define PACKED_ __attribute__((packed))

typedef struct PACKED_ _SENSOR_DATA_
{
  int x;
  int y;
  int z;
}sens_data;
typedef struct PACKED_ _POWER_MODE_
{
    uint8_t DR_BW :4;
    uint8_t powerdown : 1;
    uint8_t Zen : 1;
    uint8_t Yen : 1;
    uint8_t Xen : 1;

} power_mode;

////////// for high pass filter config
typedef enum _MODES_
{
    normal = 0x00, /// reset by reading the refrence register
    filter_data = 0x01,
    normal_ = 0x02,
    auto_int_ev = 0x03

} mode_filter;

typedef struct PACKED_ _HIGH_PASS_FILTER_
{

    mode_filter mode : 2;
    uint8_t cuttoff : 4;

} high_pass_filter;

typedef enum _FULL_SCALE_
{
    _245 = 0,
    _500 = 1,
    _2000 = 3,
} full_scale;

typedef struct PACKED_ CONTROL_
{
    uint8_t big_endian : 1;
    full_scale scale : 2;
    uint8_t self_test : 2;
    uint8_t spi_int : 1;
} control;


/////// this structure contains the bit fields and the user have to init with proper settings
typedef struct _CONFIG_GYRO_
{
    power_mode pwrmode;
    high_pass_filter hp_filter;
    control control_conf;
    uint8_t out_conf;

} config_gyro;

///////////////// this structure contains the fifo confguration
typedef struct PACKED_ _FIFO_SRC_REG_
{
    uint8_t Watermark : 1;
    uint8_t overrun : 1;
    uint8_t empty : 1;
    uint8_t data_level : 5;
} fifo_status;

typedef enum _FIFO_MODE
{
    bypass = 0,
    fifo = 1,
    stream
} fifo_mode;

typedef struct _CONFIG_FIFO_
{
    fifo_mode fmode : 2;
    uint8_t watermark : 5;

} config_fifo;

//////////////// this structure is used to config the interrupt for the sensor
typedef struct PACKED_ _INT1_STATUS_
{
    uint8_t reserved : 1;
    uint8_t INT_AACT : 1;
    uint8_t Zh : 1;
    uint8_t Zl : 1;
    uint8_t Yh : 1;
    uint8_t Yl : 1;
    uint8_t Xh : 1;
    uint8_t Xl : 1;
} int1_status;

typedef struct PACKED_ _INT1_CONFIG
{
    uint8_t int_en : 1;
    uint8_t int1_boot : 1;
    uint8_t int_actv : 1;
    uint8_t PP_od : 1; // o for push pull and 1 for open drain
    uint8_t int2_data_rdy : 1;
    uint8_t int2_wtm : 1;
    uint8_t int2_ovrn : 1;
    uint8_t int2_fifo_empty : 1;
} int1_conf;

typedef struct PACKED_ INT1_SRC_
{
    uint8_t and_or : 1;
    uint8_t latch_ir : 1;
    uint8_t Zhie : 1;
    uint8_t Zlie : 1;
    uint8_t yhie : 1;
    uint8_t ylie : 1;
    uint8_t xhie : 1;
    uint8_t xlie : 1;
} int1_src;

typedef struct PACKED_ _STATUS_
{
    uint8_t zyxor : 1;
    uint8_t zor : 1;  /// overrun error
    uint8_t yor : 1;
    uint8_t xor : 1;
    uint8_t Zyxda : 1;
    uint8_t zda : 1;  ///// z new data avilable
    uint8_t yda : 1;
    uint8_t xda : 1;
} status_reg;
typedef struct _CONFIG_INT_
{
    int1_conf int1_config;
    int1_src  int1_source;
    uint8_t int_sel;
    uint8_t int_th_xh;
    uint8_t int_th_xl;
    uint8_t int_th_yh;
    uint8_t int_th_yl;
    uint8_t int_th_zh;
    uint8_t int_th_zl;
    int8_t duration;
} config_int;

void init(config_gyro * );
//////////////////////////////////////////////////////////////////////////////////
///////////// used to config the fifo
void conf_fifo( config_fifo *);

////////////////////////////////////////////////////////////////////////////
////////////////// used to comfig rhe interrupt
void conf_int(config_int *);

void read_sensor(sens_data * ); // the pointer size must be 3 

uint8_t read_status(void);
/////////////////////////////////////////////////////////////////////////////////
/////////////// interrupt handler
void INT1_IRQ_handler(void);

void INT1_callback(void);

void INT2_IRQ_handler(void);

void INT2_callback(void);
/////////////////////////////////////////////////////////////////////
uint8_t read_temp(void);
#endif