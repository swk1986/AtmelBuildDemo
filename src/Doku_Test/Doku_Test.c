/*
 * Doku_Test.c
 *
 * Created: 30.01.2023 11:27:18
 *  Author: jweyda
 */ 


#include <avr/io.h>


uint8_t		HW_Init(void)
/** *************************************
* \brief		Initialization µC-settings
* **************************************
* \author		wj
* **************************************
* \param		-
* \return		 0 = ok
****************************************/
{
	
	// SVB Flex
	// initialization values PORTB:
	//PB.0	DO		uC		TAuf		test signal button open
	//PB.1	DO		uC		TZu			test signal button close
	//PB.2	DO		uC		TUZu		test signal for simulating the higher-level signal UZu
	//PB.3	DO		uC		TUAuf		test signal for simulating the higher-level signal UAuf
	//PB.4	DO		uC		Poti		test signal potentiometer
	//PB.5	DO		uC		frei		free
	//PB.6	DO		uC		LED_err		error LED
	//PB.7	DO		uC		LED_gn		LED mode green
	PORTB = 0x00;
	DDRB = 0xff;

	// initialization PORTC:
	//PC.0	AI		uC		UH			stroke
	//PC.1	AI		uC		UG			speed
	//PC.2	AI		uC		TLED_2		current error LED in mA
	//PC.3	AI		uC		TLED_rd		current LED red in mA
	//PC.4	AI		uC		TLED_gn		current LED green in mA
	//PC.5	DO		uC		frei		free
	//PC.6	AI		uC		UZ2			supply voltage Kl. 2 (brown)
	//PC.7	AI		uC		UZ1			supply voltage Kl. 1 (blue)

	PORTC = 0x00;
	DDRC = 0x20;
	DIDR0 = 0x1f;

	// initialization PORTD:
	//PD.0	DI		uC		Auf			signal button open
	//PD.1	DI		uC		Zu			signal button close
	//PD.2	DI		uC		UAuf		control signal UAuf
	//PD.3	DI		uC		UZu			control signal UZu
	//PD.4	DI		uC		SW			button learn
	//PD.5	DO		uC		LED_rd		LED mode red
	//PD.6	DO		uC		LK3OUT		LK3 output
	//PD.7	CI		uC		LK3IN		LK3 intput
	PORTD = 0x10;
	DDRD = 0x60;
	

	// Initialization ADC:
	// The ADC is operated with a clock frequency of 125kHz.
	ADMUX  = 0x40;
	ADCSRA = 0x96;
	ADCSRB = 0x00;
	
	// prepare LK3
	ACSR = (1 << ACBG);

	// Initialization Timer 2
	// Creation of time slices
	// Mode 1 Phase Correct PWM, TOP = 0xff
	// Outputs are not served
	OCR2A  = 0;
	OCR2B  = 0;
	TCCR2A = 0x01;
	TCCR2B = 0x01;
	TIMSK2 = 0x01;

	return(0);
}


int main(void)
{
	
	HW_Init();
	
	
    while(1)
    {
        //TODO:: Please write your application code 
		
		PORTB = PORTB ^ 0x40;
    }
}


