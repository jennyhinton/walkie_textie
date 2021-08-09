/*
 * buttons.h
 *
 *  Created on: Jul 28, 2021
 *      Author: Jenny
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

void interupt_init (void);
interrupt void xint1_isr(void);
interrupt void xint2_isr(void);

#endif /* BUTTONS_H_ */
