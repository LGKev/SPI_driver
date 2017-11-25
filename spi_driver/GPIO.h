/*
 * GPIO.h
 *
 *  Created on: Nov 25, 2017
 *      Author: kevin
 */

#ifndef GPIO_H_
#define GPIO_H_


#include "msp.h"

/*  EPAPER
 *=============
 * @name: configure SPI Pins- epaper
 * @brief: Configures the GPIO pins, for EPAPER display
 *      CS          P1.0
 *      RESET       P1.4
 *      D/C         PULLED LOW FOR 3 WIRE SPI, epaper
 *      MOSI        P1.3
 *      CLK         P1.1
 *
 *
 *          @important: use this for the final, currently you don't have access to those pins easily, configure for another SPI port
 * */
void configure_epaper_pins();


/*  AMAZON SSD1331
 *=============
 * @name: configure SPI Pins- Amazon Display
 * @brief: Configures the GPIO pins, for AMazon display, using pins  on port 10,UCB3
 *      CS          P4.0
 *      RESET       P6.1
 *      D/C         P6.0
 *      MOSI        P10.2
 *      CLK         P10.1
 *
 * */
void configure_SSD1331_pins();




#endif /* GPIO_H_ */
