#ifndef UART_H
#define UART_H


/**
 * @file    uart.h
 * @version 1.0.1
 * @brief   UART communication functions for AVR.
 * @details This header file contains the function prototypes and macro definitions 
 *          for UART communication for the AVR microcontroller.
 * @author  A.Atta
 * @date    24/01/2025
 **/


/*========			Linking Section Start				========*/

#include <avr/io.h>

/*========			Linking Section End				========*/


/*========			Definitions Section Start			========*/

#define UART_BAUD_RATE	9600

#define BAUD_PRESCALE	( ( F_CPU/(16UL * UART_BAUD_RATE) ) - 1)	/* Baud Rate Prescaler */

/*========			Definitions Section End				========*/


/*========			Functions Declarations Section Start		========*/

/**
 * @brief	Function to initialize UART0 registers.
 * @param	unsigned int
 * @return	void
 **/
void UART_init(unsigned int);

/**
 * @brief	Function to transmit unsigned character using UART0.
 * @param	unsigned char
 * @return	void
 **/
void UART_TxChar(unsigned char);

/**
 * @brief	Function to receive unsigned character using UART0.
 * @param	void
 * @return	UDR0 "received character" 
 **/
unsigned char UART_RxChar(void);

/*========			Functions Declarations Section End		========*/


#endif /* UART_H */
