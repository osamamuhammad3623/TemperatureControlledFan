/*
 *	File name: main.c
 *  Created on: Oct 6, 2021
 *  Author: osama
 */

#include "application_logic.h"
#include "dc_motor.h"
#include "adc.h"
#include "lm35_sensor.h"
#include "lcd.h"
#include "std_types.h"

int main(void){

	/* initialize used modules */
	DcMotor_init();

	ADC_ConfigType adc_options = {Internal,Division_Factor_8};
	ADC_init(&adc_options);

	LCD_init();
	LCD_displayStringRowColumn(0, 2, "Fan is ");
	LCD_displayStringRowColumn(1, 2, "Temp = ");

	extern uint8 g_temperature; /* extern global var. from application logic file */
	while(1){

		g_temperature = LM35_getTemperature();
		processApplicationLogic();
		update_LCD_info();
	}

	return 0;
}
