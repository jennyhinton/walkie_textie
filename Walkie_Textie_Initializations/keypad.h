/*
 * keypad.h
 *
 *  Created on: Jul 14, 2021
 *      Author: Jenny
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

bool capslock = 0;
char message[160]{'\0'}; // {'\0'} initialized the array with a null value

const char* key_scan(void);

#endif /* KEYPAD_H_ */
