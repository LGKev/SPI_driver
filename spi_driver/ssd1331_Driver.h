/*
 * ssd1331_Driver.h
 *
 *  Created on: Nov 25, 2017
 *      Author: kevin
 */

#include "msp.h"

#ifndef SSD1331_DRIVER_H_
#define SSD1331_DRIVER_H_

/* Commands Table 10 of the SSD1331 Data Sheet */
#define CMD_SET_COLUMN_ADDRESS                  0x15
#define CMD_SET_ROW_ADDRESS                     0x75
#define CMD_SET_CONTRAST_FOR_COLOR_A            0x81
#define CMD_SET_CONTRAST_FOR_COLOR_B            0x82
#define CMD_SET_CONTRAST_FOR_COLOR_C            0x83
#define CMD_MASTER_CURRENT_CTL                  0x87
#define CMD_SET_PRECHARGE_A                     0x8A
#define CMD_SET_PRECHARGE_B                     0x8B
#define CMD_SET_PRECHARGE_C                     0x8C
#define CMD_REMAP                               0xA0
#define CMD_SET_DISPLAY_LINE                    0xA1
#define CMD_SET_DISPLAY_OFFSET                  0xA2
#define CMD_MODE_NORMAL                         0xA4
#define CMD_MODE_ALL_ON                         0xA5
#define CMD_MODE_ALL_OFF                        0xA6
#define CMD_MODE_INVERSE                        0xA7
#define CMD_SET_MUX_RATIO                       0xA8
#define CMD_DIM_MODE                            0xAB
#define CMD_SET_MASTER_CONFIG                   0xAD
#define CMD_SET_DISPLAY_ON_DIM                  0xAC
#define CMD_SET_DISPLAY_OFF_SLEEP               0xAE
#define CMD_SET_DISPLAY_ON_NORMAL               0xAF
#define CMD_POWER_SAVE_MODE                     0xB0
#define CMD_DISPLAY_CLOCK_DIV                   0xB3
#define CMD_GRAY_SCALE_TABLE                    0xB8
#define CMD_ENABLE_LINEAR_GRAY                  0xB9
#define CMD_SET_PRECHARGE_LEVEL                 0xBB
#define CMD_SET_PRECHARGE                       0xB1
#define CMD_SET_V_COMH                          0XBE

/* Commands Graphical Accleration */
#define CMD_DRAW_LINE                           0x21
#define CMD_DRAW_RECT                           0x22
#define CMD_COPY                                0x23
#define CMD_DIM_WINDOW                          0x24
#define CMD_CLEAR_WINDOW                        0x25
#define CMD_FILL_ENABLE_DISABLE                 0x26 ///allow for fill
#define CMD_CONTINUOUS_SCROLL                   0x27
#define CMD_DEACTIVATE_SCROLL                   0x2E
#define CMD_ACTIVATE_SCROLL                     0x2F



#define RESET               0x02
#define CS                  0x01
#define DC                  0x00
#define MOSI                0x04
#define CLK                 0x02


/* Fundamental Function */
/*
 *  @name: write_data in SPI
 *  @brief: Takes care of the necessary GPIO to initiate writing data
 *          R/W# is held LOW
 *          CS# is held LOW
 *          D/C#is held HIGH
 * */
void write_data(uint8_t _data);

/*
 * @name: write_command in SPI
 * @brief: Takes care of the necessary GPIO to initiate writing a command
 *          R/W# is held LOW
 *          CS# is held LOW
 *          D/C#is held LOW
 * */
void write_command(uint8_t _command);


/*
 *  @name: read_status in 6800 Series parallel interface
 *  @brief: Gets current status of the display: Busy, Idle, (double check what it actually returns)
 *          R/W# is held HIGH
 *          CS# is held LOW
 *          D/C#is held LOW
 * */
void read_status(void);

/*  @name: Read Data in 6800 Series parallel interface
 *  @brief: Reads current data
 *          R/W# is held HIGH
 *          CS# is held LOW
 *          D/C#is held HIGH
 * */

/* @name: Init display
 * @brief: initializes the display with long list of configurations for SSD1331
 *  Assuming using EUSCI B3 as the spi module.
 * */
void initialize_Display();

/* @name: fillRect_HW
 * @brief: uses the driver for display to make a rectangle or a line.
 *  */
void fillRect_HW(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t fillcolor);


#endif /* SSD1331_DRIVER_H_ */
