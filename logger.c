/*
 * logger.c
 *
 * Created: 4/7/2015 10:01:43 PM
 *  Author: CEchols
 */ 

#ifndef F_CPU	
	#define F_CPU 8000000 //Default Value!
	#warning "F_CPU not defined for logger.h"
#endif

#ifndef BAUD
	#define BAUD 9600 //Default Values!
	#warning "BAUD not defined for logger.h"
#endif

#define BRC ((F_CPU/16/BAUD) - 1)

#include "logger.h"
#include <stdio.h>
#include <avr/io.h>

FILE usart0_io = FDEV_SETUP_STREAM(USART0SendByte, NULL, _FDEV_SETUP_WRITE);

//This is all you need to call!
void Start_USART_Logging(){
	USART_Init(BRC);
	//Use user defined stream as stdout!
	stdout=&usart0_io;
}

//This method will be used to print info to the USART line for logging.
int USART0SendByte(char u8Data, FILE *stream)
{
	//wait while previous byte is completed
	while(!(UCSR0A&(1<<UDRE0))){};
	// Transmit data
	UDR0 = u8Data;
	return 0;
}

void USART_Init(unsigned int ubbr){
	//Set BAUD Rate
	UBRR0H = (unsigned char)(ubbr>>8);
	UBRR0L = (unsigned char)(ubbr);
	
	//Enable Receiver and Transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	//Set frame Format: 8bit data, 2 stop bits
	UCSR0C = (1<<USBS0)|(3<<UCSZ00);
}