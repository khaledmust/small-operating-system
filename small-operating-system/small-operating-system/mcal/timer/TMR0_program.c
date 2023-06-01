

/** INCLUDE LIBRARIES **/
#include "../../SERVICE/common_macros.h"
#include "../../SERVICE/standard_types.h"

/** INCLUDE LOWER LAYER FILES **/
#include "../dio/DIO_interface.h"

/** INCLUDE DRIVER FILES **/
#include "TMR0_interface.h"
#include "TMR0_private.h"
#include "TMR0_config.h"

uint32_t u32_gs_tmr0nuofovs = 0 ;   /** VARIABLE TO HOLD THE NUMBER OF OVER FLOWS **/


/****************************************************************/
/** Description : Initialize Timer 0 with some configurations   */
/** @param      VOID                                            */
/** @return     TMR0_init status                                */
/****************************************************************/
TMR0_init_error TMR0_init(void)
{
	TMR0_init_error en_a_initstatus = VALID_INIT ; /** VARIABLE TO RETURN THE STATUS OF INITIALIZATION **/
	
    /* COUNTER MODE OF TMR0 */
	#if TIMER0_CLK_SRC == EXTERNAL_CLK_SRC
	
	  /* EXTERNAL PIN AS CLOCK SOURCE */
	  DIO_setpindir(DIO_PORTB , DIO_PIN0 , DIO_PIN_INPUT);

	  //DIO_SETPULLUPS(DIO_PORTB , DIO_PIN0 );
	  
	 #if CNT0_EXTERNAL_EDGE_MODE == FALLING_EDGE_CNT
	  
	  clear_bit(TCCR0 , 0);
	  set_bit(TCCR0 , 1);
	  set_bit(TCCR0 , 2);
	  
	  en_a_initstatus = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	  
	 #elif CNT0_EXTERNAL_EDGE_MODE == RISING_EDGE_CNT
	  
	  set_bit(TCCR0 , 0);
	  set_bit(TCCR0 , 1);
	  set_bit(TCCR0 , 2);
	  en_a_initstatus = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #endif
	 
	 /* TIMER MODE OF TMR0 */
	#elif TIMER0_CLK_SRC == INTERNAL_CLK_SRC
	
	 #if TIMER0_MODE == TMR0_NORMAL_MODE
	 
	 clear_bit(TCCR0 , 7);
	 clear_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 clear_bit(TCCR0 , 5);
	 
	 en_a_initstatus = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 /* ENABLE INTERRUPT */
// 	 set_bit(SREG , 7);
// 	 set_bit(TIMSK , 0);
	 
	 #elif TIMER0_MODE == TMR0_FASTPWM_NON_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 en_a_initstatus = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR0_FASTPWM_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 set_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 en_a_initstatus = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR_PHASE_CORRECT_NON_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 en_a_initstatus = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR_PHASE_CORRECT_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 set_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 en_a_initstatus = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR0_CTC_MODE
	 
	 DIO_setpindir(DIO_PORTB , DIO_PIN3 , DIO_PIN_OUTPUT); /** SET CTC BIT AS OUTPUT PIN **/
	 
	 clear_bit(TCCR0 , 7);
	 clear_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 
	 /* ENABLE INTERRUPT */
	 //set_bit(SREG , 7);
	 //set_bit(TIMSK , 1);
	 
	 en_a_initstatus = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	  #if COMPARE_ACTION == SET_ON_COMPARE
	   
	   set_bit(TCCR0 , 4);
	   set_bit(TCCR0 , 5);
	   
	  #elif COMPARE_ACTION == CLEAR_ON_COMPARE
	   
	   clear_bit(TCCR0 , 4);
	   set_bit(TCCR0 , 5);
	   
	  #elif COMPARE_ACTION == TOOGLE_ON_COMPARE
	   
	   set_bit(TCCR0 , 4);
	   clear_bit(TCCR0 , 5);
	  #endif
	 #endif
	#endif
	
	return en_a_initstatus ; /** RETURN THE STATUS OF INITIALIZATION **/
}


/*******************************************************************************/
/** Description : Start Timer 0 with the assigned prescaller or clock source   */
/** @param      VOID                                                           */
/** @return     TMR0_start status                                              */
/*******************************************************************************/
TMR0_start_error TMR0_start(void)
{
	TMR0_start_error en_a_startstatus = VALID_START ; /** VARIABLE TO RETURN THE STATUS OF START **/
	
	#if TIMER0_PRESCALER_VAL == PRESCALER_1024
	
	set_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	
	en_a_startstatus = VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER0_PRESCALER_VAL == NO_PRESCALER
	
	set_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	en_a_startstatus = VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_8
	
	clear_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	en_a_startstatus = VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_64
	
	set_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	en_a_startstatus = VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_256
	
	clear_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	
	en_a_startstatus = VALID_START ; /** START DONE PROBERLY **/
	
	#endif
	
	return en_a_startstatus ; /** RETURN THE STATUS **/
}

/*******************************************************************************/
/** Description : Stop Timer 0                                                 */
/** @param      VOID                                                           */
/** @return     TMR0_stop status                                               */
/*******************************************************************************/
TMR0_stop_error TMR0_stop(void)
{
	TMR0_stop_error en_a_stopStatus = VALID_STOP ; /** VARIABLE TO RETURN THE STATUS **/
	
	/** SET CONFIGURATIONS AS NO CLOCK SOURCE **/
	clear_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	en_a_stopStatus = VALID_STOP ; /** STOP DONE PROPERLY **/
	
	return en_a_stopStatus ; /** RETURN THE STATUS **/
	
}

/*******************************************************************************/
/** Description : Sets delay using Timer 0                                     */
/** @param      delay_in_milliseconds                                          */
/** @return     TMR0_delay status                                              */
/*******************************************************************************/
TMR0_delay_error TMR0_delayms(uint32_t u32_a_delayms)
{
	
	uint32_t u32_a_overflowcounter = 0 ;
	
	TMR0_delay_error en_a_delaystatus = NOT_VALID_DELAY ; /** VARIABLE TO RETURN THE STATUS **/
	
	/******************************************************************************************/
	/**               THIS CALCULATIONS CONFIGURED AS F_CPU   16 MHZ                         **/
	/******************************************************************************************/
	#if TIMER0_PRESCALER_VAL == PRESCALER_1024  /** CHECK THE PRESCALLER FROM CONFIG FILE **/
	 
        u32_gs_tmr0nuofovs = (u32_a_delayms / 16.384);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/ 
	
        TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	    en_a_delaystatus = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_256

	    u32_gs_tmr0nuofovs = (u32_a_delayms / 4.096);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	    TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	    en_a_delaystatus = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_64
		
	    u32_gs_tmr0nuofovs = (u32_a_delayms / 1.024);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	    TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	    en_a_delaystatus = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == NO_PRESCALER
	
	    u32_gs_tmr0nuofovs = (u32_a_delayms / 0.016);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	    TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	    en_a_delaystatus = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#endif
	
	TMR0_start(); /** START TMR0 PRESCALLER **/
	
	while ( u32_a_overflowcounter < u32_gs_tmr0nuofovs ) /** STUCK IN THIS LOOP UNTILL THIS CONDITION IS FALSE **/
	{
		while((TIFR & (1 << 0)) == 0); /** DO NOTHING UNTILL THIS FLAG RAISED (OVERFLOW HAPPENED) **/
		
		set_bit(TIFR , 0);        /** CLEAR THE FLAG BY SOFTWARE **/
		
		u32_a_overflowcounter++ ; /** INCREASE THE OVERFLOWS BY ONE **/
	}
	
	u32_gs_tmr0nuofovs = 0 ; /** REINTIALIZE THE OVERFLOWS COUNTER TO 0 AGAIN **/

	TMR0_stop();   /** STOP TMR0 TOSTART FROM 0 WHEN IT CALLED AGAIN **/
	
	return en_a_delaystatus ; /** RETURN THE STATUS **/
}

/*******************************************************************************/
/** Description : Sets delay using Timer 0                                     */
/** @param      delay_in_microseconds                                          */
/** @return     TMR0_delay status                                              */
/*******************************************************************************/
TMR0_delay_error TMR0_delaymicros(uint32_t u32_a_delaymicros)
{
	uint32_t u32_a_overflowcounter = 0 ;
	
	TMR0_delay_error en_a_delaystatus = NOT_VALID_DELAY ; /** VARIABLE TO RETURN THE STATUS **/
	
	/******************************************************************************************/
	/**               THIS CALCULATIONS CONFIGURED AS F_CPU   1 MHZ                          **/
	/******************************************************************************************/
	#if TIMER0_PRESCALER_VAL == PRESCALER_1024  /** CHECK THE PRESCALLER FROM CONFIG FILE **/
	
	u32_gs_tmr0nuofovs = (u32_a_delaymicros / 262144);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	en_a_delaystatus = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_256

	u32_gs_tmr0nuofovs = (u32_a_delaymicros / 65536);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	en_a_delaystatus = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_64
	
	u32_gs_tmr0nuofovs = (u32_a_delaymicros / 16384);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	en_a_delaystatus = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == NO_PRESCALER
	
	u32_gs_tmr0nuofovs = (u32_a_delaymicros / 256);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	en_a_delaystatus = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#endif
	
	TMR0_start(); /** START TMR0 PRESCALLER **/
	
	while( u32_a_overflowcounter < u32_gs_tmr0nuofovs ) /** STUCK IN THIS LOOP UNTILL THIS CONDITION IS FALSE **/
	{
		while((TIFR & (1 << 0)) == 0); /** DO NOTHING UNTILL THIS FLAG RAISED (OVERFLOW HAPPENED) **/
		
		set_bit(TIFR , 0);        /** CLEAR THE FLAG BY SOFTWARE **/
		
		u32_a_overflowcounter++ ; /** INCREASE THE OVERFLOWS BY ONE **/
	}
	
	u32_a_overflowcounter = 0 ; /** REINTIALIZE THE OVERFLOWS COUNTER TO 0 AGAIN **/

	TMR0_stop(); /** STOP TMR0 TOSTART FROM 0 WHEN IT CALLED AGAIN **/
	
	return en_a_delaystatus ; 
}
