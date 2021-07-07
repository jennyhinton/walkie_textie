/*
 * screen.c
 *
 *  Created on: Jul 1, 2021
 *      Author: Jenny
 */

void screen_init (void) //SPI protocol IDK how to send these commands yet
{
    40        //display start line at 0
    A1        //set SEG to bottom view
    C0        //set normal direction com0-com63
    A4        //set all pixels off
    A6        //set inverse display off
    A2        //set bias 1/9 (duty 1/65)
    2F        //set power control, booster, regulator and follower on
    27        //set contrast
    81
    10
    FA        //set temperature compensation curve to -0.11 %/C
    90
    AF        //set display on
}

void keypad_init (void)
{

}
