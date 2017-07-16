/*
 * Keypad.h
 *
 * Created: 6/15/2017 8:03:33 PM
 *  Author: MOHAMED YOUSEF
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char byte;

#define SET_BIT(reg, index) reg |= (1 << index)
#define CLR_BIT(reg, index)	reg &= (~(1 << index))
#define GET_BIT(reg, index)((reg >> index) & 0x01)
#define TOG_BIT(reg, index)	reg ^= (1 << index)

#define Kpad_ddr  DDRD
#define Kpad_port PORTD
#define Kpad_pin  PIND

#define MAX_COL 4
#define MAX_ROW 4

void Kpad_init(void);
byte Kpad_get_key_position(void);
byte Kpad_get_key_value(byte key_position);

#endif /* KEYPAD_H_ */