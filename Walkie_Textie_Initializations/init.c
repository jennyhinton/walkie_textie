/*
 * init.c
 *
 *  Created on: Jul 1, 2021
 *      Author: Jenny
 */

#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "spia.h"               //spia initialization and help functions

void screen_init (void)
{
    // Step 5. User specific code:
       const char *sdata[13];
       sdata[0] = "40";       //display start line at 0
       sdata[1] = "A1";       //set SEG to bottom view
       sdata[2] = "C0";       //set normal direction com0-com63
       sdata[3] = "A4";       //set all pixels off
       sdata[4] = "A6";       //set inverse display off
       sdata[5] = "A2";       //set bias 1/9 (duty 1/65)
       sdata[6] = "2F";       //set power control, booster, regulator and follower on
       sdata[7] = "27";       //set contrast
       sdata[8] = "81";
       sdata[9] = "10";
       sdata[10] = "FA";       //set temperature compensation curve to -0.11 %/C
       sdata[11] = "90";
       sdata[12] = "AF";       //set display on

       for(int i = 0; i<sizeof(sdata)/sizeof(char) ; i++)
       {
           // Transmit data
           spi_xmit(sdata[i]);
           // Wait until data is received
           while(SpiaRegs.SPIFFRX.bit.RXFFST !=1) { }
           // Check against sent data
           rdata = SpiaRegs.SPIRXBUF;
           if(rdata != sdata[i]) error();
       }
}

void keypad_init (void)
{
    /*
     * columns high impedance outputs
     * rows inputs
     * GPIO 1-12
     *
               COL1   COL2   COL3   COL4  COL5
               PIN44  PIN45  PIN48  PIN51 PIN53
    ROW1 PIN56  Q      E       R      U     O
    ROW2 PIN58  W      S       G      H     L
    ROW3 PIN60  sym    D       T      Y     I
    ROW4 PIN61  A      P      sh2    ret   bck
    ROW5 PIN64  alt    Z       V      B     $
    ROW6 PIN70  spc    X       C      N     M
    ROW7 PIN1   mike  sh1      F      J     K

     */

    // Make gpio 13 an input for row 1
    GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;   // Enable pullup on GPIO13
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;  // GPIO13 = GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO13 = 0;   // GPIO13 = input

    // Make gpio 14 an input for row 2
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;   // Enable pullup on GPIO14
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;  // GPIO14 = GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 0;   // GPIO14 = input

    // Make gpio 15 input for row 3 ... same comments as above
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO15 = 0;

    //typedef GpioCtrlRegs.GPADIR.bit.GPIO3 row3;

    // Make gpio 25 input for row 4
    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO25 = 0;

    // Make gpio 26 input for row 5
    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO26 = 0;

    // Make gpio 27 input for row 6
    GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO27 = 0;

    // Make gpio 28 input for row 7
    GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO28 = 0;

    // Make gpio 29 highZ for col 1
    GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;   // disable pullup on GPIO8
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 0;  // GPIO29 = GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO29 = 0;   // GPIO8 = input

    // Make gpio 30 highZ for col 2
    GpioCtrlRegs.GPAPUD.bit.GPIO30 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO30 = 0;

    // Make gpio 10 highZ for col 3
    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 0;

    // Make gpio 11 highZ for col 4
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 0;

    // Make gpio 12 highZ for col 5
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 1;
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 0;
}

void button_init (void)
{
    // Make gpio 1 input for Power button
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;   // Enable pullup on GPIO1
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;  // GPIO1 = GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;   // GPIO1 = input

    // Make gpio 2 input for PTT button
     GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;   // Enable pullup on GPIO2
     GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;  // GPIO2 = GPIO
     GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;   // GPIO2 = input

    // Make gpio 3 input for up button ... same comments as above
     GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;
     GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;
     GpioCtrlRegs.GPADIR.bit.GPIO3 = 0;

    // Make gpio 4 input for down button
    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO4 = 0;

    // Make gpio 5 input for left button
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO5 = 0;

    // Make gpio 6 input for right button
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 0;

    // Make gpio 7 input for center button
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 0;

    // Make gpio 8 input for volume up button
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 0;

    // Make gpio 9 input for volume down button
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 0;
}

}
