//gpio.h header file

#ifndef GPIO_H_ 							
#define GPIO_H_

int Export(int pin);

int Unexport(int pin);

int Direction(int pin, char* direction);

int Value(int pin,int val);

#endif