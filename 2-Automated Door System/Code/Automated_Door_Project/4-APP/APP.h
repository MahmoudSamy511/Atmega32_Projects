#ifndef APP_H
#define APP_H
//MCAL
#include"../1-MCAL/ADC/ADC_Interface.h"
#include"../1-MCAL/UART/UART_Interface.h"
//HAL
#include"../2-HAL/Keypad/Keypad_Interface.h"
#include"../2-HAL/LCD/LCD_Interface.h"
#include"../2-HAL/Servo_Motor/Servo_Interface.h"
//Delay
#define F_CPU  16000000UL
#include<util/delay.h>
//App Configurations
#define PASSWORD     		"12345"
#define PASSWORD_LENGTH     5
#define IR_RANGE    		300
#define OPEN_DELAY   		1500
#define CLOSE_DELAY   		1000
#define OPEN_ANGLE      	90
#define CLOSE_ANGLE      	0
//Functions Prototypes
void wrongPasswordHandling(void);
void getUserPassword(void);
void displayOptionsAndGetUserOption(void);
void checkSide(void);

#endif
