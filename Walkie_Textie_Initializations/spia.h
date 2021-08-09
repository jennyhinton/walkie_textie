/*
 * spia.h
 *
 *  Created on: Jul 14, 2021
 *      Author: Jenny
 */

#ifndef SPIA_H_
#define SPIA_H_


// Prototype statements for functions found within this file.
// interrupt void ISRTimer2(void);
void spia_init (void);
void delay_loop(void);
void spi_xmit(Uint16 a);
void spi_fifo_init(void);
void spi_init(void);
void error(void);

#endif /* SPIA_H_ */
