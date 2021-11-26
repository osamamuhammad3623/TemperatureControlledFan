/*
 *	Module: DC Motor
 *	File name: dc_motor.h
 *  Created on: Oct 6, 2021
 *  Author: osama
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "gpio.h"
#include "std_types.h"

/* Configurations */
#define ENABLE_PORT_ID	PORTB_ID
#define ENABLE_PIN_ID	PIN3_ID
#define INPUT_PORT_ID	PORTB_ID
#define INPUT1_PIN_ID	PIN0_ID
#define INPUT2_PIN_ID	PIN1_ID

typedef enum{
	Stop, CW, ACW
}DcMotor_State;


 /* functions prototypes */
void DcMotor_init();

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
