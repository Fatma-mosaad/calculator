/*
 * KeyPad_prv.h
 *
 * Created: 10/22/2023 9:29:51 AM
 *  Author: Wael
 */ 


#ifndef KEYPAD_PRV_H_
#define KEYPAD_PRV_H_

#define ROW_NUM   4
#define COL_NUM   4
#define NO_KEY   'T'

uint8 key_arr [ROW_NUM][COL_NUM] =
{
	{'1', '2', '3', '+'},
	{'4', '5', '6', '-'},
	{'7', '8', '9', '*'},
	{'.', '0', '=', '/'}
};




#endif /* KEYPAD_P RV_H_ */
