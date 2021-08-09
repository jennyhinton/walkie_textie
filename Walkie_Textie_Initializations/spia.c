/*
 * spia.c
 *
 *  Created on: Jul 14, 2021
 *      Author: Jenny
 */

#include "v170/DSP280x_headers/include/DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "spia.h"

void SPIa_init(void)    //initialize SPIa for screen. No interrupt used
{
   Uint16 sdata;  // send data
   Uint16 rdata;  // received data

// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
   InitSysCtrl();

// Step 2. Initalize GPIO:
// Setup only the GPIO only for SPI-A functionality
   InitSpiaGpio();

// Step 3. Clear all interrupts and initialize PIE vector table:
// Disable CPU interrupts
   DINT;

// Initialize PIE control registers to their default state.
// The default state is all PIE interrupts disabled and flags are cleared.
   InitPieCtrl();

// Disable CPU interrupts and clear all CPU interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt Service Routines (ISR).
// This will populate the entire table, even if the interrupt
// is not used in this example.  This is useful for debug purposes.
   InitPieVectTable();

// Step 4. Initialize all the Device Peripherals:
   spi_fifo_init();   // Initialize the Spi FIFO
   spi_init();        // init SPI
}


// Step 7. Insert all local Interrupt Service Routines (ISRs) and functions here:
void delay_loop()
{
    long      i;
    for (i = 0; i < 1000000; i++) {}
}


void error(void)
{
    asm("     ESTOP0");                     // Test failed!! Stop!
    for (;;);
}

void spi_init()
{
    SpiaRegs.SPICCR.all =0x000F;                 // Reset on, rising edge, 16-bit char bits
    SpiaRegs.SPICTL.all =0x0006;                 // Enable master mode, normal phase,
    SpiaRegs.SPIBRR =0x007F;                     // enable talk, and SPI int disabled.
    SpiaRegs.SPICCR.all =0x009F;                 // Relinquish SPI from Reset
    SpiaRegs.SPIPRI.bit.FREE = 1;                // Set so breakpoints don't disturb xmission
}

void spi_xmit(Uint16 a)
{
    SpiaRegs.SPITXBUF = a; // this may or may not be right
}

void spi_fifo_init()
{
// Initialize SPI FIFO registers
    SpiaRegs.SPIFFTX.all=0xE040;
    SpiaRegs.SPIFFRX.all=0x204f;
    SpiaRegs.SPIFFCT.all=0x0;
}
