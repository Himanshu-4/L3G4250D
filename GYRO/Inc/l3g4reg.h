#ifndef _L3G4REG_H_
#define _L3G4REG_H_

/////////////////////////////// definations of register of gyroscope ////////////////////////////////////////////////
#define WHO_AM_I 0x0F

#define CTRL_REG_1 0x20

//////////// ctrl enable reg
#define XEN 0
#define YEN 1
#define ZEN 2
#define PD  3
#define BANDWIDTH  4
#define DATARATE   6

#define CTRL_REG_2 0x21

// control register 2 setting 
#define HPCF0 0
#define HPCF1 1
#define HPCF2 2
#define HPCF3 3
#define HPM0  4
#define HPM1  5

#define CTRL_REG_3 0x22

///////// /////////////  control register 3

#define I2C_EMPTY 0
#define I2C_ORUN  1
#define I2C_WTM   2
#define I2_DRDY   3
#define PP_OD     4
#define H_LACTIVE 5
#define L1_BOOT   6
#define L1_INT    7

#define CTRL_REG_4 0x23
//////////////////////////////////// control reg 4
#define SIM 0
#define ST0 1
#define ST1 2
#define FS0 4
#define FS1 5
#define BLE 6

#define CTRL_REG_5 0x24
////////////////////////////////////// control reg 5
#define OUT_SEL0 0
#define OUT_SEL1 1
#define INT1_SEL0 2
#define INT1_SEL1 3
#define HPEN      4
#define FIFO_EN   5
#define BOOT      7


#define REFRENCE 0x25
/////////////////////////// refrence 

#define OUT_TEMP 0x26
/////////////////////////////////// out temp

#define STATUS_REG 0x27
////////////////////////////// status reg 
#define XDA  0
#define YDA  1
#define ZDA  2
#define ZYXDA 3
#define XOR   4
#define YOR   5
#define ZOR   6
#define ZYXOR 7

#define OUT_X_L 0x28

#define OUT_X_H 0x29

#define OUT_Y_L 0x2A

#define OUT_Y_H 0x2B

#define OUT_Z_L 0x2C

#define OUT_Z_H 0x2D

#define FIFO_CTRL 0x2E

#define FM0 5

#define FIFO_SRC 0x2F

#define WTM 7
#define OVRN 6
#define EMPTY 5

#define INT1_CFG 0x30

/// interrupt configuration for the sensor
#define ANDD_OR 7
#define LIR   6
#define ZHIE  5
#define ZLIE  4
#define YHIE  3
#define YLIE  2
#define XHIE  1
#define XLIE  0

#define INT1_SRC 0x31
/////////// interrupt source configuration 
#define IA  6
#define ZH  5
#define ZL  4
#define YH  3
#define YL  2
#define XH  1
#define XL  0

#define INT1_TH_X_H 0x32

#define INT1_TH_X_L 0x33

#define INT1_TH_Y_H 0x34

#define INT1_TH_Y_L 0x35

#define INT1_TH_Z_H 0x36

#define INT1_TH_Z_L 0x37

#define INT1_DURATION 0x38
//////////// wait state 
#define WAIT 7
#endif