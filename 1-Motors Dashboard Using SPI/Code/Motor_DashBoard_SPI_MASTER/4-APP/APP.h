/********************** MASTER **************************/
#ifndef APP_H
#define APP_H



//LIB Layer
#include"../5-LIB/TYPEDEF.h"
//MCAL
#include"../1-MCAL/Timers/Timer_Interface.h"
#include"../1-MCAL/DIO/DIO_interface.h"
#include"../1-MCAL/SPI/SPI_Interface.h"
//HAL Layer
#include"../2-HAL/LCD/LCD_Interface.h"
#include"../2-HAL/Keypad/Keypad_Interface.h"

extern u8 order;

/********************* APP Configurations ********************/
#define PasswordLength      5
#define Password          "51120"
#define delay			500 //ms
/************************APP Functions***********************/
void APP_Init(void);
void displayOptionsPage(void);
void takeUserOption(u8 *option);
void displayRotationOptions(void);
void getPassword(void);
void DCMotor(void);
void servoMotor(void);
void stepperMotor(void);
void stopMotors(void);

#endif
