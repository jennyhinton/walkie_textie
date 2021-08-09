/*
 * buttons.c
 *
 *  Created on: Jul 28, 2021
 *      Author: Jenny
 */

void interupt_init (void)
{
       // Step 1. Initialize System Control:
       // PLL, WatchDog, enable Peripheral Clocks
       // This example function is found in the DSP280x_SysCtrl.c file.
       InitSysCtrl();

       // Step 2. Initalize GPIO:
       // This example function is found in the DSP280x_Gpio.c file and
       // illustrates how to set the GPIO to it's default state.
       // InitGpio();  // Skipped for this example

       // Step 3. Clear all interrupts and initialize PIE vector table:
       // Disable CPU interrupts
       DINT;

       // Initialize PIE control registers to their default state.
       // The default state is all PIE interrupts disabled and flags
       // are cleared.
       // This function is found in the DSP280x_PieCtrl.c file.
       InitPieCtrl();

       // Disable CPU interrupts and clear all CPU interrupt flags:
       IER = 0x0000;
       IFR = 0x0000;

       // Initialize the PIE vector table with pointers to the shell Interrupt
       // Service Routines (ISR).
       // This will populate the entire table, even if the interrupt
       // is not used in this example.  This is useful for debug purposes.
       // The shell ISR routines are found in DSP280x_DefaultIsr.c.
       // This function is found in DSP280x_PieVect.c.
       InitPieVectTable();

       // Interrupts that are used in this example are re-mapped to
       // ISR functions found within this file.
          EALLOW;  // This is needed to write to EALLOW protected registers
          PieVectTable.XINT1 = &xint1_isr;
          PieVectTable.XINT2 = &xint2_isr;
          EDIS;   // This is needed to disable write to EALLOW protected registers

       // Step 4. Initialize all the Device Peripherals:
       // This function is found in DSP280x_InitPeripherals.c
       // InitPeripherals(); // Not required for this example


       // Step 5. User specific code, enable interrupts:
       // Enable XINT1 and XINT2 in the PIE: Group 1 interrupt 4 & 5
       // Enable INT1 which is connected to WAKEINT:
          PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
          PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // Enable PIE Gropu 1 INT4
          PieCtrlRegs.PIEIER1.bit.INTx5 = 1;          // Enable PIE Gropu 1 INT5
          IER |= M_INT1;                              // Enable CPU INT1
          EINT;                                       // Enable Global Interrupts


      // GPIO0 is XINT1, GPIO1 is XINT2
         EALLOW;
         GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 0;   // XINT1 is GPIO0
         GpioIntRegs.GPIOXINT2SEL.bit.GPIOSEL = 1;   // XINT2 is GPIO1
         EDIS;

      // Configure
         XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // Falling edge interrupt
         XIntruptRegs.XINT2CR.bit.POLARITY = 1;      // Rising edge interrupt

      // Enable XINT1 and XINT2
         XIntruptRegs.XINT1CR.bit.ENABLE = 1;        // Enable XINT1
         XIntruptRegs.XINT2CR.bit.ENABLE = 1;        // Enable XINT2

     // Step 6. IDLE loop:
        for(;;){}

    // Step 7. Insert all local Interrupt Service Routines (ISRs) and functions here:
        // If local ISRs are used, reassign vector addresses in vector table as
        // shown in Step 5
}

interrupt void xint1_isr(void)
{
    GpioDataRegs.GPBCLEAR.all = 0x4;   // GPIO34 is low
    Xint1Count++;

    // Acknowledge this interrupt to get more from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

interrupt void xint2_isr(void)
{
    GpioDataRegs.GPBCLEAR.all = 0x4;   // GPIO34 is low
    Xint2Count++;

    // Acknowledge this interrupt to get more from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
