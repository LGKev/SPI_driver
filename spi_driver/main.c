#include "msp.h"
#include "GPIO.h"
#include "ssd1331_Driver.h"
#include "spi_driver.h"

/**
 * main.c
 */

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	configure_3_Wire_SPI_OLED();


    __enable_irq();



	while(1){
	    write_data(0b10010000); //can see on scope
	}
}
