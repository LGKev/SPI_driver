/*
 * spi_driver.h
 *
 *  Created on: Nov 25, 2017
 *      Author: kevin
 */

#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

/*
 * @name: Configure 3 Wire SPI
 * @brief: Configures EUSCI_A0 for SPI 3 wire
 * @important: use this for the epaper
 * */
void configure_3_Wire_SPI();

/*
 * @name: Configure 3 Wire SPI for the amazon RGB OLED display
 * @brief: configures EUSCI_B3 for SPI 3 wire, 8 bits of data
 * @important use this for the amazon display only, testing spi module.
 * */
void configure_3_Wire_SPI_OLED();


#endif /* SPI_DRIVER_H_ */
