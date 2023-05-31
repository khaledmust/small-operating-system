



#ifndef DIO_H_
#define DIO_H_

#include "../../MCU/Registers.h"

// All driver macros

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//direction defines
#define IN 0
#define OUT 1

//value defines
#define LOW 0
#define HIGH 1

// All drive functions prototype

void DIO_init(uint8_t portNumber ,uint8_t pintNumber , uint8_t direction);  // initialize dio direction

void DIO_write(uint8_t portNumber ,uint8_t pintNumber , uint8_t value);

void DIO_toggle(uint8_t portNumber ,uint8_t pintNumber);

void DIO_read(uint8_t portNumber ,uint8_t pintNumber , uint8_t* value);



#endif /* DIO_H_ */