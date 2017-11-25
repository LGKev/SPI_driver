/*
 * spi_driver.c
 *
 *  Created on: Nov 25, 2017
 *      Author: kevin
 */

#include "msp.h"
#include "spi_driver.h"
#include "GPIO.h"



/* Necessary Steps to configure the EUSCI MOdule
 *  1) UCSWRST
 *  2) intiailize all eusci registers
 *  3) configure ports (call the gpio function)
 *  4) Clear the UCSWRST bit
 *  5)Enable interrupts like RX and TX
 * */
void configure_3_Wire_SPI_OLED(){
    EUSCI_B3->CTLW0 = UCSWRST; // set to a 1
    EUSCI_B3->CTLW0 |= UCMST | UCSSEL__SMCLK | UCCKPL; // master mode, and set to the system clock 3.25MhZ should be ok, default for arduino is 4Mhz , if too fast divide out

    //configure ports
    configure_SSD1331_pins();

    EUSCI_B3->CTLW0 &= ~UCSWRST;

    //configure any interrupts
    EUSCI_B3->IFG = 0x00; //clear any flags
    EUSCI_B3->IE = UCTXIE | UCRXIE;

    //register interrupt
    NVIC_EnableIRQ(EUSCIB3_IRQn);
}

















/*============================================================================================================================================*/
/*============================================================================================================================================*/
/*============================================================================================================================================*/

                                             /*          INTERRUPT HANDLER FOR SPI B3         */

/*============================================================================================================================================*/
/*============================================================================================================================================*/
/*============================================================================================================================================*/
void EUSCIB3_IRQHandler(){
    if(UCB3IFG & UCTXIFG){
        UCB3IFG &= ~UCTXIFG;
    }
    if(UCB3IFG & UCRXIFG){
        //likely never going to happen
        UCB3IFG &= ~UCRXIFG;
    }
}


