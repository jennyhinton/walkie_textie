

/**
 * main.c
 *
 *  Created on: Jul 1, 2021
 *      Author: Jenny
 */
//#include "init.h"
//#include <stdio.h>

int main(void)
{
    //while (1){};
    //screen_init ();

    //track mode, volume, current message, screen position

    //call all initializations

    //interrupts
        //power
        //volume
            //check current level
            //adjust based on trigger
        //arrows
            //enter: check if keyboard
                //keyboard:
                //updating current message:
                    //while (keypad = 0)
                    //update_message(key_scan());
                    //update screen
                //send
                    // check tx
                    // send
                // storing messages:
                    // ?
        //PTT
            //pause speaker
            //start mic
            //check tx
            //send message

       //rx
            // check audio/text type
            //if audio type
                //check mode
                //if silent mode
                    //generate error message
                    //update screen
                    //vibrate
                //if normal mode
                    //check volume
                    //play message over speaker
            //if text type
                //check mode
                //if talkie mode
                    //delay
                    //check mode again
                //if normal mode
                    //display message
                    //update screen
                    //vibrate
                    //play alert
                //if silent mode
                    //display message
                    //vibrate

        //infinite loop

	return 0;
}
