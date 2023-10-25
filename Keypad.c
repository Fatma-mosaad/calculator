/*
 * key.c
 *
 * Created: 10/22/2023 9:29:31 AM
 *  Author: fatma
 */ 
 

#include "std_types.h"
#include "gpio.h"
#include "Keypad_prv.h"
#include "Keypad_cfg.h"
#include "KeyPad.h"
#include <util/delay.h>/* For the delay functions */

 uint8 ROW[4]={
		KEYPAD_ROW1_PIN_ID,KEYPAD_ROW2_PIN_ID,KEYPAD_ROW3_PIN_ID,KEYPAD_ROW4_PIN_ID};
 uint8 COL[4]={
		KEYPAD_COL1_PIN_ID,KEYPAD_COL2_PIN_ID,KEYPAD_COL3_PIN_ID,KEYPAD_COL4_PIN_ID};

void keypad_init(void)
{
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW1_PIN_ID, PIN_OUTPUT);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW2_PIN_ID, PIN_OUTPUT);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW3_PIN_ID, PIN_OUTPUT);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW4_PIN_ID, PIN_OUTPUT);

		GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL1_PIN_ID, PIN_INPUT);
		GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL2_PIN_ID, PIN_INPUT);
		GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL3_PIN_ID, PIN_INPUT);
		GPIO_setupPinDirection(KEYPAD_COL_PORT_ID, KEYPAD_COL4_PIN_ID, PIN_INPUT);

		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW1_PIN_ID, LOGIC_HIGH);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW2_PIN_ID, LOGIC_HIGH);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW3_PIN_ID, LOGIC_HIGH);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT_ID, KEYPAD_ROW4_PIN_ID, LOGIC_HIGH);


	
}

uint8 keypad_getkey(void)
{
	uint8 r,c,key=NO_KEY;
	for(r=0;r<ROW_NUM;r++){
		GPIO_writePin(KEYPAD_COL_PORT_ID,ROW[r],LOGIC_LOW);
		for(c=0;c<COL_NUM;c++){
			if(GPIO_readPin(KEYPAD_COL_PORT_ID,COL[c]==LOGIC_LOW))
			{
				key=key_arr[r][c];
				_delay_ms(10);
				while(GPIO_readPin(KEYPAD_COL_PORT_ID,COL[c])==LOGIC_LOW);
				_delay_ms(10);
			}
		}
		GPIO_writePin(KEYPAD_COL_PORT_ID,ROW[r],LOGIC_HIGH);

	}
	return key;




}
			
		







