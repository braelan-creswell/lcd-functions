#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lcd.h"
#include "gpio.h"
#include <unistd.h>

int main(void) {

	lcd_init();

	printf("test\n");

	u_int8_t stuff[] = "ECE 331";

	lcd_print(stuff);


	lcd_instruct(lcd_Clear);
	lcd_instruct(lcd_Home);

	volatile int i = 0;
	while (stuff[i] != 0)
    {
        lcd_writechar(stuff[i]);
        i++;
        sleep(1);
    }


	lcd_destroy();
}
