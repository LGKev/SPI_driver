/*
 * ssd1331_Driver.c
 *
 *  Created on: Nov 25, 2017
 *      Author: kevin
 */

#include "ssd1331_Driver.h"
#include "msp.h"
#include "GPIO.h"

void write_data(uint8_t _data){
        //CS low, D/C high
    P4OUT &= ~BIT0;
    P6OUT |= BIT0;
    UCB3TXBUF = _data;
}
void write_command(uint8_t _command){
    //CS low, D/C low //:TODO: come back and use the macros
    P4OUT &= ~BIT0;
    P6OUT &= ~BIT0;
    UCB3TXBUF = _command;
}
