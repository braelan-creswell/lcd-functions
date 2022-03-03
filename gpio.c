#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gpio.h"

int Export(int pin) {
	FILE *Exp;
	Exp = fopen("/sys/class/gpio/export", "w");
	fprintf(Exp,"%d", pin);
	fclose(Exp);
	return 0;
}

int Unexport(int pin) {
	FILE *UExp;
        UExp = fopen("/sys/class/gpio/unexport", "w");
        fprintf(UExp,"%d", pin);
        fclose(UExp);
	return 0;
}

int Direction(int pin, char* direction){
	FILE *Dir;
	char filename[64];
	snprintf(filename, sizeof(filename),"/sys/class/gpio/gpio%d/direction",pin); 
        Dir = fopen(filename, "w");
        fprintf(Dir,"%s",direction);
        fclose(Dir);
	return 0;
}

int Value(int pin,int val){
	FILE *VAL;
	char filename[64];
        snprintf(filename, sizeof(filename),"/sys/class/gpio/gpio%d/value",pin);
        VAL = fopen(filename, "w");
        fprintf(VAL,"%d", val);
        fclose(VAL);
	return 0;
}