#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lcd.h"
#include "gpio.h"
#include <unistd.h>

void lcd_init(void) {
	Export(lcd_D7); //Export pins from Kernel
	Export(lcd_D6);
	Export(lcd_D5);
	Export(lcd_D4);
	Export(lcd_E);
	Export(lcd_RS);
	Direction(lcd_D7, "out"); //Set pins direction to output
	Direction(lcd_D6, "out");
	Direction(lcd_D5, "out");
	Direction(lcd_D4, "out");
	Direction(lcd_E, "out");
	Direction(lcd_RS, "out");
	
	Value(lcd_E, 0); //Enable Pin intially low
	
	sleep(0.015); //ensure screen is powered up for long enough
	lcd_write(0, lcd_FunctionReset);
	sleep(0.005);
	lcd_write(0, lcd_FunctionReset);
	usleep(150);
	lcd_write(0, lcd_FunctionReset);
	usleep(150);
	lcd_write(0, lcd_FunctionSet);
	usleep(100);
	lcd_instruct(lcd_FunctionSet);
	usleep(100);
	lcd_instruct(lcd_Clear);
	usleep(100);
	lcd_instruct(lcd_EntryMode);
	usleep(100);
	lcd_instruct(lcd_DisplayOn);
}

void lcd_write(u_int8_t flag, u_int8_t data) {
	Value(lcd_RS, 0);
	if(flag == 1) Value(lcd_RS, 1); //set register select to data mode if requested
	
	Value(lcd_E, 0);  //Enable pin initially low
	
	Value(lcd_D7, 0);
	if(data & 1<<7) Value(lcd_D7, 1); //Check 7th bit
	Value(lcd_D6, 0);
	if(data & 1<<6) Value(lcd_D6, 1); //check 6th bit
	Value(lcd_D5, 0);
	if(data & 1<<5) Value(lcd_D5, 1); //check 5th bit
	Value(lcd_D4, 0);
	if(data & 1<<4) Value(lcd_D4, 1); //check 4th bit
	
	Value(lcd_E, 1);
	usleep(1);
	Value(lcd_E, 0);
	usleep(1);
}

void lcd_instruct(u_int8_t instruction) {
	lcd_write(0, instruction);
	lcd_write(0, instruction << 4);
}

void lcd_writechar(u_int8_t data) {
	lcd_write(1, data);
	lcd_write(1, data << 4);
	
}

void lcd_print(u_int8_t *string) {
	volatile int i = 0;                             // char counter
    while (string[i] != 0)
    {
        lcd_writechar(string[i]);
        i++;
        usleep(80);                             
    }
}

void lcd_destroy(void) {
	Unexport(lcd_D7); //Unexport pins from Kernel
	Unexport(lcd_D6);
	Unexport(lcd_D5);
	Unexport(lcd_D4);
	Unexport(lcd_E);
	Unexport(lcd_RS);
}