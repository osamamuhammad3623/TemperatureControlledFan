/*
 *	File name: application_logic.c
 *  Created on: Oct 7, 2021
 *  Author: osama
 */

#include "application_logic.h"
#include "lcd.h"
#include "dc_motor.h"


/* global variables */
uint8 g_temperature=0;
Fan_State fan_state = Turned_OFF;


/* application function implementations */
void update_LCD_info(void){
	LCD_moveCursor(0, 9);
	fan_state ? LCD_displayString("ON ") : LCD_displayString("OFF");
	LCD_moveCursor(1, 9);
	if (g_temperature >= 100) {
		LCD_intgerToString(g_temperature);
	} else {
		LCD_intgerToString(g_temperature);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}
}

void processApplicationLogic(void){
	if (g_temperature < 30) {
		fan_state = Turned_OFF;
		DcMotor_Rotate(Stop, 0); /*stop the fan*/

	} else if (g_temperature >= 120) {
		fan_state = Turned_ON;
		DcMotor_Rotate(CW, 100); /*rotate with max speed*/

	} else if (g_temperature >= 90) {
		fan_state = Turned_ON;
		DcMotor_Rotate(CW, 75); /*rotate with 75% of max speed*/

	} else if (g_temperature >= 60) {
		fan_state = Turned_ON;
		DcMotor_Rotate(CW, 50); /*rotate with 50% of max speed*/

	} else if (g_temperature >= 30) {
		fan_state = Turned_ON;
		DcMotor_Rotate(CW, 25); /*rotate with 25% of max speed*/
	}
}
