

// include .h files
#include "DIO.h"


// function definition

// -------------init------------------------

void DIO_init(uint8_t portNumber ,uint8_t pintNumber , uint8_t direction){
	
	switch (portNumber)
	{
		case PORT_A :
		
		if(direction == IN){
			DDRA &= ~(1<<pintNumber); //input
		}
		
		else if(direction == OUT){
			DDRA |= (1<<pintNumber); //output
		}
		
		else{
			// error handling
		}
		break;
		
		case PORT_B :
		
		if(direction == IN){
			DDRB &= ~(1<<pintNumber); //input
		}
		
		else if(direction == OUT){
			DDRB |= (1<<pintNumber); //output
		}
		
		else{
			// error handling
		}
		break;
		
		
		
		case PORT_C :
		
		if(direction == IN){
			DDRC &= ~(1<<pintNumber); //input
		}
		
		else if(direction == OUT){
			DDRC |= (1<<pintNumber); //output
		}
		
		else{
			// error handling
		}
		break;
		
		case PORT_D :
		
		if(direction == IN){
			DDRD &= ~(1<<pintNumber); //input
		}
		
		else if(direction == OUT){
			DDRD |= (1<<pintNumber); //output
		}
		
		else{
			// error handling
		}
		break;
		
	}
}

// ---------------Write----------------------

void DIO_write(uint8_t portNumber ,uint8_t pintNumber , uint8_t value){
	
	switch (portNumber)
	{
		case PORT_A :
		
		if(value == LOW){
			PORTA &= ~(1<<pintNumber); //write 0
		}
		
		else if(value == HIGH){
			PORTA |= (1<<pintNumber); //write 1
		}
		
		else{
			// error handling
		}
		break;
		
		case PORT_B :
		
		if(value == LOW){
			PORTB &= ~(1<<pintNumber); //write 0
		}
		
		else if(value == HIGH){
			PORTB |= (1<<pintNumber); //write 1
		}
		
		else{
			// error handling
		}
		break;
		
		
		
		case PORT_C :
		
		if(value == LOW){
			PORTC &= ~(1<<pintNumber); //write 0
		}
		
		else if(value == HIGH){
			PORTC |= (1<<pintNumber); //write 1
		}
		
		else{
			// error handling
		}
		break;
		
		case PORT_D :
		
		if(value == LOW){
			PORTD &= ~(1<<pintNumber); //write 0
		}
		
		else if(value == HIGH){
			PORTD |= (1<<pintNumber); //write 1
		}
		
		else{
			// error handling
		}
		break;
		
	}
}


//-----------------read------------------------

void DIO_read(uint8_t portNumber ,uint8_t pintNumber , uint8_t* value){
	
	switch(portNumber){
		
		case PORT_A :
		*value = (PINA &(1<<pintNumber))>>pintNumber ;  //get state read bit 0 or 1
		break;
		
		case PORT_B :
		*value = (PINB &(1<<pintNumber))>>pintNumber ;
		break;
		
		case PORT_C :
		*value = (PINC &(1<<pintNumber))>>pintNumber ;
		break;
		
		case PORT_D :
		*value = (PIND &(1<<pintNumber))>>pintNumber ;
		break;
		
		default:
		//error handling
		break;
		
	}
	
}


//-----------------toggle------------------------

void DIO_toggle(uint8_t portNumber ,uint8_t pintNumber){
	
	switch(portNumber){
		
		case PORT_A :
		PORTA ^= (1<<pintNumber) ;
		break;
		
		case PORT_B :
		PORTB ^= (1<<pintNumber) ;
		break;
		
		case PORT_C :
		PORTC ^= (1<<pintNumber) ;
		break;
		
		case PORT_D :
		PORTD ^= (1<<pintNumber) ;
		break;
		
		default:
		//error handling
		break;
		
	}
	
}