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

    P4OUT |= BIT0; //pull cs high again.
    P6OUT ^= BIT0;


}
void write_command(uint8_t _command){
    //CS low, D/C low //:TODO: come back and use the macros
    P4OUT &= ~BIT0;
    P6OUT &= ~BIT0;
    UCB3TXBUF = _command;
    P4OUT |= BIT0; //pull cs high again.
    P6OUT ^= BIT0;
}


void initialize_Display(){
    write_command(CMD_SET_DISPLAY_OFF_SLEEP);
    write_command(CMD_REMAP);
    write_command(0x76);
    write_command(CMD_SET_DISPLAY_LINE);
    write_command(0x0);
    write_command(CMD_SET_DISPLAY_OFFSET);
    write_command(0x0);
    write_command(CMD_MODE_NORMAL);
    write_command(CMD_SET_MUX_RATIO);
    write_command(0x3F); //1/164th duty!?
    write_command(CMD_SET_MASTER_CONFIG);
    write_command(0x8E);
    write_command(CMD_POWER_SAVE_MODE);
    write_command(0x0B); //turn off power save mode
    write_command(CMD_SET_PRECHARGE);
    write_command(0x31);
    write_command(CMD_DISPLAY_CLOCK_DIV);
    write_command(0xF0); // checkout table on page 30 of datasheet for more info
    write_command(CMD_SET_PRECHARGE_A);
    write_command(0x64);
    write_command(CMD_SET_PRECHARGE_B);
    write_command(0x78);
    write_command(CMD_SET_PRECHARGE_C); //lol at the typo in the adafruit library, this is just setting up the speed at which pre charge occurs for color a,b,c
    write_command(0x64);
    write_command(CMD_SET_PRECHARGE_LEVEL);
    write_command(0x3A);
    write_command(CMD_SET_V_COMH);
    write_command(0x3E); //max vcom level
    write_command(CMD_MASTER_CURRENT_CTL);
    write_command(0x06);
    write_command(CMD_SET_CONTRAST_FOR_COLOR_A);
    write_command(255);
    write_command(CMD_SET_CONTRAST_FOR_COLOR_B);
    write_command(255);
    write_command(CMD_SET_CONTRAST_FOR_COLOR_C);
    write_command(255);






    uint8_t x =0;
    uint8_t y =0;

    for(x=0; x<200; x++){
        for(y=0; y< 64; y++){
            write_data(255);
            write_data(255);
            write_data(255);

        }
    }


    write_command(CMD_SET_DISPLAY_ON_NORMAL);
    uint16_t delay;
    for(delay=0; delay < 1000; delay++);
}




void fillRect_HW(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t fillcolor){
    x = 128 - x- 1;
    y = 64 - y - 1;

//
    write_command(CMD_FILL_ENABLE_DISABLE);
    write_command(0x01);

    write_command(x & 0xFF);
    write_command(y & 0xFF);
    write_command((x+w-1) & 0xFF);
    write_command((y+h-1) & 0xFF);


    write_command((uint8_t)((fillcolor >> 11) << 1));
    write_command((uint8_t)((fillcolor >> 5)& 0x3F));
    write_command((uint8_t)((fillcolor >> 1)& 0x3F));

    write_command((uint8_t)((fillcolor >> 11) << 1));
    write_command((uint8_t)((fillcolor >> 5)& 0x3F));
    write_command((uint8_t)((fillcolor >> 1)& 0x3F));

    uint16_t delay;
    for(delay=0; delay < 1000; delay++);

}
