/*
 * logger.h
 *
 * Created: 4/7/2015 10:01:32 PM
 *  Author: CEchols
 */ 


#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>

int USART0SendByte(char u8Data, FILE *stream);
void Start_USART_Logging();
void USART_Init(unsigned int ubbr);


#endif /* LOGGER_H_ */