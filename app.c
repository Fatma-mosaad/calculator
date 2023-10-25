/*
 * app.c
 *
 *  Created on: Oct 21, 2023
 *      Author: hp
 */
#include "lcd.h"
#include "KeyPad.h"
#include"app.h"
#include <util/delay.h> /* For the delay functions */

void init_app(void)
{
	LCD_init();
	keypad_init();
}

void Main_Options(void)
{
	uint8 num1;
	uint8 num2;
	uint8 oprand;
	uint8 key;
	uint16 result;
	LCD_displayStringRowColumn(0,1,"welcome");
	LCD_clearScreen();
	LCD_moveCursor(1,1);
	num1=keypad_getkey();
	LCD_displayCharacter(num2);
	oprand=keypad_getkey();
	LCD_displayCharacter(oprand);
	num2=keypad_getkey();
	LCD_displayCharacter(num2);
	key=keypad_getkey();
	LCD_displayCharacter(key);


	switch(oprand)
	{
	case '+':
		result=num1+num2;

		break;
	case '-':
		result=num1-num2;

		break;
	case '*':
		result=num1*num2;

		break;
	case '/':
		if(num2==0){
			LCD_displayStringRowColumn(2,1,"invalid");
		}
		else{
			result=num1/num2;


		}


		break;
	default:
		break;
	}
	if(key=='=')
	{
		LCD_intgerToString(result);
	}
	else{

	}



}
