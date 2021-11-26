/*
 *	File name: application_logic.h
 *  Created on: Oct 7, 2021
 *  Author: osama
 */

#ifndef APPLICATION_LOGIC_H_
#define APPLICATION_LOGIC_H_

#include "std_types.h"

/* definitions */
typedef enum {
	Turned_OFF,Turned_ON
}Fan_State;


/* application function prototypes */
void update_LCD_info(void);
void processApplicationLogic(void);

#endif /* APPLICATION_LOGIC_H_ */
