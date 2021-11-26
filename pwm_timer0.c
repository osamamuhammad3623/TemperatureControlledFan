/*
 *	File name: pwm_timer0.c
 *  Created on: Oct 7, 2021
 *  Author: osama
 */

#include "pwm_timer0.h"
#include "gpio.h"
#include <avr/io.h>

/* Configurations */
#define PWM_SIGNAL_PORT_ID	PORTB_ID
#define PWM_SIGNAL_PIN_ID	PIN3_ID


void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; // Set Timer Initial Value to 0

	/* configure the timer
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
	GPIO_setupPinDirection(PWM_SIGNAL_PORT_ID, PWM_SIGNAL_PIN_ID, PIN_OUTPUT);
	OCR0 = duty_cycle;
}
