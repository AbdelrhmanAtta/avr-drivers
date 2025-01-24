#ifndef UART_H
#define UART_H

#define F_CPU	8000000UL
#define UART_BAUD_RATE	9600
#define BAUD_PRESCALE	( ( F_CPU/(16UL * UART_BAUD_RATE) ) - 1)	// Configures UBRRn prescaler value.


void UART_init(unsigned int);
void UART_TxChar(unsigned char);					// Transmit Characters.
unsigned char UART_RxChar(void);					// Recives Characters.


#endif
