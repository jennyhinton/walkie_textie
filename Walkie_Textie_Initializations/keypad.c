/*
 * keypad.c
 *
 *  Created on: Jul 14, 2021
 *      Author: Jenny

     * columns high impedance / row inputs
     * GPIO 1-12
     * Trigger column by pulling low, then check each row
     * Definitely need to credit https://forum.arduino.cc/t/interfacing-blackberry-q10-keypad-to-arduino-and-the-oled-typewriter/342989
     *
               COL1   COL2   COL3   COL4  COL5
               GP8    GP9    GP10   GP11  GP12
    ROW1 GPIO1  Q      E       R      U     O
    ROW2 GPIO2  W      S       G      H     L
    ROW3 GPIO3  sym    D       T      Y     I
    ROW4 GPIO4  A      P      sh2    ret   bck
    ROW5 GPIO5  alt    Z       V      B     $
    ROW6 GPIO6  spc    X       C      N     M
    ROW7 GPIO7  mike  sh1      F      J     K

     */

char key_scan(void)
{
    bool sym = 0;       //track character vs symbol
    char chr = 0;       //current character
    char symb = 0;      //current symbol
    bool shift = 0;     //shift key

    bool alt = 0;           //idk what to do with these really
    bool backspace = 0;
    bool shl = 0;
    bool shr = 0;
    bool ret = 0;

    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;   // GPIO8 = output
    GpioDataRegs.GPADATPUD.bit.GPIO8 = 1;   // set col 1 low
    if (GpioDataRegs.GPADAT.bit.GPIO1 == 0)         //row 1
    {
        chr = 'q';
        symb = '#';
    }
    if (GpioDataRegs.GPADAT.bit.GPIO2 == 0)         //row 2
    {
        chr = 'w';
        symb = '1';
    }
    if (GpioDataRegs.GPADAT.bit.GPIO3 == 0)         //row 3
    {
        sym = 1;
    }
    if (GpioDataRegs.GPADAT.bit.GPIO4 == 0)         //row 4
    {
        chr = 'a';
        symb = '*';
    }
    if (GpioDataRegs.GPADAT.bit.GPIO5 == 0)         //row 5
    {
        alt = 1;
    }
    if (GpioDataRegs.GPADAT.bit.GPIO6 == 0)         //row 6
    {
        chr = ' ';
        symb = ' ';
    }
    if (GpioDataRegs.GPADAT.bit.GPIO7 == 0)         //row 7
    {
        chr = '~';
        symb = '0';
    }
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 0;   // GPIO8 = input
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;   // GPIO9 = output
    GpioDataRegs.GPADATPUD.bit.GPIO9 = 1;   // set col 2 low

    if (GpioDataRegs.GPADAT.bit.GPIO1 == 0)         //row 1
   {
       chr = 'e';
       symb = '2';
   }
   if (GpioDataRegs.GPADAT.bit.GPIO2 == 0)         //row 2
   {
       chr = 's';
       symb = '4';
   }
   if (GpioDataRegs.GPADAT.bit.GPIO3 == 0)         //row 3
   {
       chr = 'd';
       symb = '5';
   }
   if (GpioDataRegs.GPADAT.bit.GPIO4 == 0)         //row 4
   {
       chr = 'p';
       symb = '@';
   }
   if (GpioDataRegs.GPADAT.bit.GPIO5 == 0)         //row 5
   {
       chr = 'x';
       symb = '8';
   }
   if (GpioDataRegs.GPADAT.bit.GPIO6 == 0)         //row 6
   {
       chr = 'z';
       symb = '7';
   }
   if (GpioDataRegs.GPADAT.bit.GPIO7 == 0)         //row 7
   {
       shift = 1;
       shl = 1;
   }
   GpioCtrlRegs.GPADIR.bit.GPIO9 = 0;   // GPIO9 = input
   GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;   // GPIO10 = output
   GpioDataRegs.GPADATPUD.bit.GPIO10 = 1;   // set col 3 low

   if (GpioDataRegs.GPADAT.bit.GPIO1 == 0)         //row 1
      {
          chr = 'r';
          symb = '3';
      }
      if (GpioDataRegs.GPADAT.bit.GPIO2 == 0)         //row 2
      {
          chr = 'g';
          symb = '/';
      }
      if (GpioDataRegs.GPADAT.bit.GPIO3 == 0)         //row 3
      {
          chr = 't';
          symb = '(';
      }
      if (GpioDataRegs.GPADAT.bit.GPIO4 == 0)         //row 4
      {
          shift = 1;
          shr = 1;
      }
      if (GpioDataRegs.GPADAT.bit.GPIO5 == 0)         //row 5
      {
          chr = 'v';
          symb = '?';
      }
      if (GpioDataRegs.GPADAT.bit.GPIO6 == 0)         //row 6
      {
          chr = 'c';
          symb = '9';
      }
      if (GpioDataRegs.GPADAT.bit.GPIO7 == 0)         //row 7
      {
          chr = 'f';
          symb = '6';
      }
      GpioCtrlRegs.GPADIR.bit.GPIO10 = 0;   // GPIO10 = input
      GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;   // GPIO11 = output
      GpioDataRegs.GPADATPUD.bit.GPIO11 = 1;   // set col 4 low

     if (GpioDataRegs.GPADAT.bit.GPIO1 == 0)         //row 1
     {
         chr = 'u';
         symb = '_';
     }
     if (GpioDataRegs.GPADAT.bit.GPIO2 == 0)         //row 2
     {
         chr = 'h';
         symb = ':';
     }
     if (GpioDataRegs.GPADAT.bit.GPIO3 == 0)         //row 3
     {
         chr = 'y';
         symb = ')';
     }
     if (GpioDataRegs.GPADAT.bit.GPIO4 == 0)         //row 4
     {
         ret = 1;
     }
     if (GpioDataRegs.GPADAT.bit.GPIO5 == 0)         //row 5
     {
         chr = 'b';
         symb = '!';
     }
     if (GpioDataRegs.GPADAT.bit.GPIO6 == 0)         //row 6
     {
         chr = 'n';
         symb = ',';
     }
     if (GpioDataRegs.GPADAT.bit.GPIO7 == 0)         //row 7
     {
         chr = 'j';
         symb = ';';
     }
     GpioCtrlRegs.GPADIR.bit.GPIO11 = 0;   // GPIO11 = input
     GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;   // GPIO12 = output
     GpioDataRegs.GPADATPUD.bit.GPIO12 = 1;   // set col 5 low

     if (GpioDataRegs.GPADAT.bit.GPIO1 == 0)         //row 1
        {
            chr = 'o';
            symb = '+';
        }
        if (GpioDataRegs.GPADAT.bit.GPIO2 == 0)         //row 2
        {
            chr = 'l';
            symb = '"';
        }
        if (GpioDataRegs.GPADAT.bit.GPIO3 == 0)         //row 3
        {
            chr = 'i';
            symb = '-';
        }
        if (GpioDataRegs.GPADAT.bit.GPIO4 == 0)         //row 4
        {
            backspace = 1;
        }
        if (GpioDataRegs.GPADAT.bit.GPIO5 == 0)         //row 5
        {
            chr = '$';
            symb = '`';
        }
        if (GpioDataRegs.GPADAT.bit.GPIO6 == 0)         //row 6
        {
            chr = 'M';
            symb = '.';
        }
        if (GpioDataRegs.GPADAT.bit.GPIO7 == 0)         //row 7
        {
            chr = 'k';
            symb = '\';
        }
        GpioCtrlRegs.GPADIR.bit.GPIO12 = 0;   // GPIO12 = input

    if (backspace)
        return 'BS';
    if (ret)
        return '\n';

    if (shift)
        chr = chr + 42      // i cant remember the number to get to capital

    if (sym)
        return symb;
    else
        return chr;

}
