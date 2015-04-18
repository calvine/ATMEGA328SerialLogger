# ATMEGA328SerialLogger
A simple header and c file that enables the ATMEL ATMEGA 328 and similar family of micro processors to use printf from the standard library to output data on the hardware USART pins.

With this you can use printf to print data out on the MCU USART lines! Note that to get support for %f you have to add some options to your linker:

-Wl,-u,vfprintf -lprintf_flt

To use this library simply do the following!

1. Add the logger.h and logger.c file in your project
2. Define F_CPU (Clock speed of CPU) and BAUD (Desired Serial Baud rate) if you have not already in your code. Having these defines in the code before the #include directive will prevent compiler warnings!
3. Add #include "logger.h" to your code.
4. Call Start_USART_Logging() in your setup code.