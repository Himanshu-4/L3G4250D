#include "gyro.h"

////////////////// callin the init function for initializing the gyro
void init(config_gyro * config)
{
    __IO uint8_t var =0;
     var = read_reg(WHO_AM_I);  // it must print 0xD3 
    var = 0;
     
    /// write the power mode data to the register
    var = (config->pwrmode.DR_BW <<BANDWIDTH ) | (config->pwrmode.powerdown << PD)\
    | (config->pwrmode.Xen <<XEN)| (config->pwrmode.Yen << YEN) | (config->pwrmode.Zen <<ZEN);
    write_reg(CTRL_REG_1 , var);
    
    /// config the high pass filter configurtion
    var =0;
    var = (config->hp_filter.mode << HPM0) | (config->hp_filter.cuttoff);
    write_reg(CTRL_REG_2 , var);

    /////// gyro configurations 
    var =0;
    var = (config->control_conf.big_endian<<BLE) | (config->control_conf.scale << FS0)\
     | (config->control_conf.self_test << ST0) | (config->control_conf.spi_int << SIM);
    write_reg(CTRL_REG_4 , var);

    /////output data configuration select // fifo must be enabled
    var =0;
    var = read_reg(CTRL_REG_5);
    var |= (1 << HPEN) | (1<< FIFO_EN) | (config->out_conf );
     write_reg(CTRL_REG_5, var);
}

void conf_fifo(config_fifo * config)
{
     ///config the fifo register 
    uint8_t var =0;
    var = (config->fmode << FM0) | (config->watermark);

    write_reg(FIFO_CTRL , var);

}

void conf_int(config_int * config)
{
    /////// configure the interrupt 
    uint8_t var =0;
    var = (config->int1_config.int_en << L1_INT) | (config->int1_config.int1_boot << L1_BOOT) | (config->int1_config.int_actv << H_LACTIVE)\
           | (config->int1_config.PP_od << PP_OD) | (config->int1_config.int2_data_rdy << I2_DRDY) | (config->int1_config.int2_wtm <<I2C_WTM)\
           | (config->int1_config.int2_ovrn << I2C_ORUN) | (config->int1_config.int2_fifo_empty << I2C_EMPTY);

    write_reg(CTRL_REG_3 , var);
    
    var =0;
    
    var = read_reg(CTRL_REG_5);
    var |= (config->int_sel << INT1_SEL0);
    write_reg(CTRL_REG_5 , var);

    var =0;
    var = (config->int1_source.and_or << ANDD_OR) | (config->int1_source.latch_ir <<LIR) |(config->int1_source.Zhie << ZHIE)\
          | (config->int1_source.Zlie << ZLIE) |(config->int1_source.yhie<<YHIE) | (config->int1_source.ylie <<YLIE)\
          | (config->int1_source.xhie <<XHIE) | (config->int1_source.xlie <<XLIE);
       
    write_reg(INT1_CFG , var);

    write_reg(INT1_TH_X_H , config->int_th_xh);
    write_reg(INT1_TH_X_L , config->int_th_xl);
    write_reg(INT1_TH_Y_H , config->int_th_yh);
    write_reg(INT1_TH_Z_H , config->int_th_zh);
    write_reg(INT1_TH_Z_L , config->int_th_zl);

    write_reg(INT1_DURATION , config->duration);
}


void read_sensor(sens_data * data)
{
   uint8_t buff[6];
   read_data(buff , 6);
    
   data->x = ~( ((uint16_t)(buff[1] | (buff[2] << 8))) -1);
   data->y = ~( ((uint16_t)(buff[3] | (buff[4] << 8))) -1);
   data->z = ~( ((uint16_t)(buff[5] | (buff[6] << 8))) -1);

}
uint8_t read_temp(void)
{
    return read_reg(OUT_TEMP);
}


uint8_t read_status(void)
{
    return read_reg(STATUS_REG);
    
}

void INT1_IRQ_handler()
{
    INT1_callback();
}

void INT2_IRQ_handler(void)
{
    INT2_callback();
}

__WEAK void INT1_callback(void)
{

}
__WEAK void INT2_callback(void)
{

}




