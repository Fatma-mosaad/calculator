/*
 * main.c
 *
 *  Created on: Oct 21, 2023
 *      Author: hp
 */


#include"app.h"
#include <avr/io.h>

#include <util/delay.h> /* For the delay functions */




int main(void)
{
	init_app();

	while(1)
		{
			Main_Options();
		}


}


