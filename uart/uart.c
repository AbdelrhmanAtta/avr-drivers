#include <avr/io.h>
#include "uart.h"

/*
 * 8-N-1 Format.
 * Takes 'ubrr' as a parameter.
 * 'ubrr' is baud rate prescaler defined in header file.
 */
void UART_init(unsigned int ubrr)
{
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;

	UCSR0B = (1 << RXEN0)|(1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

/*
 * Transmits unsigned characters.
 * Takes 'ch' as a parameter.
 * 'ch' is the desired unsigned character to send.
 */
void UART_TxChar(unsigned char ch)
{
	while(!((UCSR0A) & (1 << UDRE0)));
	UDR0 = ch;
}

/*
 * Receives unsigned characters.
 */
unsigned char UART_RxChar(void)
{
	while(!((UCSR0A) & (1 << RXC0)));
	return UDR0;
}
