/**
 * @file	UART.c
 * @version	1.0.1
 * @brief	UART protocol source file for AVR.
 * @details	This file include essential functions for AVR to perform UART communication.
 * @author	A.Atta
 * @date	24/01/2025
 **/


/*========			Linking Section Start			========*/

#include <avr/io.h>

#include "uart.h"

/*========			Linking Section End			========*/


/*========			Function Definition Section Start	========*/

/**
 * Function:	UART_init(usigned int);
 * Use:		Intilaise UART0 registers.
 * Input:	unsigned int ubrr (baud rate prescaler value)
 * Output:	void
 **/
void UART_init(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0B = (1 << RXEN0)|(1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

/**
 * Function:	UART_TxChar(unsigned char);
 * Use:		Transmits unsigned character
 * Input:	unsigned character 'ch'
 * Output:	void
 **/
void UART_TxChar(unsigned char ch)
{
	while(!((UCSR0A) & (1 << UDRE0)));
	UDR0 = ch;
}

/**
 * Function:	UART_RxChar(void);
 * Use:		Recives unsigned character.
 * Input:	void
 * Output:	unsigned character
 **/
unsigned char UART_RxChar(void)
{
	while(!((UCSR0A) & (1 << RXC0)));
	return UDR0;
}

/*========			Definition Defention Section End	========*/


/*================================================================================
 * Change Log.
 * 
 * Date			By		Description
 * ----------		--------	------------------------------------------
 * 28/01/2025		A.Atta		Added comments for clarity.
 */

