/*
 * Keypad.c
 *
 * Created: 6/15/2017 8:03:57 PM
 *  Author: MOHAMED YOUSEF
 */ 

#include "Keypad.h"

void Kpad_init(void){
	/*
	 *4*4 keypad matrix at port d
	 *
	 *we use col pd0 to pd3 as o/p
	 *row pd4 to pd7 as i/p with pull up
	 */
	Kpad_ddr = 0x0F;
	Kpad_port = 0xF0;
}

byte Kpad_get_key_position(void){
	byte col_counter, row_counter;
	while (1) {
		for (col_counter = 0;col_counter < MAX_COL;col_counter++) {
			Kpad_ddr = 1 << col_counter;
			_delay_ms(2);
			for (row_counter = 0;row_counter < MAX_ROW;row_counter++) {
				_delay_ms(2);
				if(!(Kpad_pin & (1 << row_counter + 4) ) ) {
					while(! (Kpad_pin & (1<<row_counter + 4))); //get only one number per press
					return ((row_counter * 4) + col_counter + 1);
				}
			}
		}
	}
}

byte Kpad_get_key_value(byte key_position){
	byte key=0;
	
	switch(key_position)
	{
		case 1:key = '7';
		break;
		case 2:key = '4';
		break;
		case 3:key = '1';
		break;
		case 4:key = 'c';
		break;
		case 5:key = '8';
		break;
		case 6:key = '5';
		break;
		case 7:key = '2';
		break;
		case 8:key = '0';
		break;
		case 9:key = '9';
		break;
		case 10:key = '6';
		break;
		case 11:key = '3';
		break;
		case 12:key = '=';
		break;
		case 13:key = '%';
		break;
		case 14:key = '*';
		break;
		case 15:key = '-';
		break;
		case 16:key = '+';
		break;
	}
	return key;
}
