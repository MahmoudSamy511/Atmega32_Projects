/********************************************************
	      <-------Modification------->
 *******************************************************
 	 ==>> Added Servo Motor To DashBoard.
 	 ==>> Used My delay Function Based On Timer0.
 *****************************************************
 *******************************************************/
//LIB Layer
#include"../5-LIB/TYPEDEF.h"
//MCAL
#include"../1-MCAL/Timers/Timer_Interface.h"
//HAL Layer
#include"../2-HAL/LCD/LCD_Interface.h"
#include"../2-HAL/Keypad/Keypad_Interface.h"
#include"../2-HAL/DC_Motor/DC_Motor_Interface.h"
#include"../2-HAL/Stepper_Motor/Stepper_Motor_Interface.h"
#include"../2-HAL/Servo_Motor/Servo_Interface.h"
#define delay				1000 //ms
/* ********************Set your own password************* */
#define PasswordLength      5
#define Password          "51120"
void displayOptionsPage(){
	LCD_enu_Clear();
	LCD_enu_SendString("1-DC    3-Servo");
	LCD_enu_SetCursor(1, 0);
	LCD_enu_SendString("2-Stepper 4-Exit");
}
void takeUserOption(u8 *option){
	while(1){
		Keypad_enu_getKey(option);
		if(*option == '1' || *option == '2' || *option == '3' || *option == '4')break;
	}
}
void displayRotationOptions(){
	LCD_enu_Clear();
	LCD_enu_SendString("1-Rotate CW ");
	LCD_enu_SetCursor(1, 0);
	LCD_enu_SendString("2-Rotate CCW");
}
u16 returnAngle(u8 * array){
	u16 k = 0;
	for(u8 i = 0 ; i<3 ; i++){
		// ignore non entered digits
		if(array[i] == 'a') break;
		k = k*10 + (array[i] - '0');
	}
	return k;
}
int main(void){
	Keypad_enu_Init();
	LCD_enu_Init();
	DC_Motor_enu_Init(1, 1);
	STEP_Motor_enu_Init();
	Servo_enu_Init();
	Timers_enu_Init(TIMER0, NORMAL_MODE, CLK_8);
	u8 savedPass[] = Password , pass[PasswordLength], Index=0, checkCounter = 0,homeFlag = 0,inputFlag = 0;
	LCD_enu_SendString("Hello, User :)");
	Timers_enu_delay_ms(delay);
	LCD_enu_Clear();
	LCD_enu_SendString("Enter Password:");
	LCD_enu_SetCursor(1, 0);
	while(1){
		/************************************ Taking Password Section*************************************/
		u8 key=0,order = 0;
		Keypad_enu_getKey(&key);
		if(key != KEYPAD_U8_NO_KEY_PRESSED){
			LCD_enu_SendChar('*');
			pass[Index] = key;
			Index++;
			checkCounter++;
		}
		if(checkCounter == PasswordLength){
			for(int j =0 ;j<PasswordLength ; j++){
				if(pass[j] != savedPass[j]){
					inputFlag = 1;
					break;
				}
			}
			if (inputFlag){
				Index =0;
				checkCounter =0;
				inputFlag = 0;
				LCD_enu_Clear();
				LCD_enu_SendString("Wrong Password");
				LCD_enu_SetCursor(1, 0);
				LCD_enu_SendString("Try Again!");
				Timers_enu_delay_ms(delay);
				LCD_enu_Clear();
				LCD_enu_SendString("Enter Password:");
				LCD_enu_SetCursor(1, 0);
			}else{
				//To display this message only once
				if(!homeFlag){
					LCD_enu_Clear();
					LCD_enu_SendString("Welcome :)");
					LCD_enu_SetCursor(1, 0);
					LCD_enu_SendString("Choose Motor ..");
					homeFlag = 1;
					Timers_enu_delay_ms(delay);
				}
				displayOptionsPage();
				takeUserOption(&order);
		/************************************DC Motor Section*************************************/
				if(order == '1'){
					displayRotationOptions();
					takeUserOption(&order);
					// Rotate DC Motors CW
					if(order == '1'){
						DC_Motor_enu_Rotate(MOTOR1, CW);
						DC_Motor_enu_Rotate(MOTOR2, CW);
					}
					// Rotate DC Motors CCW
					else if (order == '2'){
						DC_Motor_enu_Rotate(MOTOR1, CCW);
						DC_Motor_enu_Rotate(MOTOR2, CCW);
					}
		/****************************** Stepper Motor Section **************************************/
				}else if(order == '2'){
					// Take Stepper Motor Angle
					LCD_enu_Clear();
					LCD_enu_SendString("Enter Angle:");
					u8 stepperMotorAngle[3],angleCounter = 0 ;
					// Display and Storing Angle
					while(angleCounter!=3){
						Keypad_enu_getKey(&key);
						if(key != KEYPAD_U8_NO_KEY_PRESSED && key != '='){
							LCD_enu_SendChar(key);

							stepperMotorAngle[angleCounter] = key;
							angleCounter++;
							Timers_enu_delay_ms(200);
						}else if(key == '=') {
							// if user entered angle of one or two digits
							if(angleCounter==1) {stepperMotorAngle[1]  = 'a';break;}
							if(angleCounter==2) {stepperMotorAngle[2]  = 'a';break;}
						}
					}
					displayRotationOptions();
					takeUserOption(&order);
					// Rotate Stepper Motor CW With Entered Angle
					if(order == '1'){
						STEP_Motor_enu_Rotate(CW, returnAngle(stepperMotorAngle) );
						Timers_enu_delay_ms(delay);
					}
					// Rotate Stepper Motor CCW With Entered Angle
					else if (order == '2'){
						STEP_Motor_enu_Rotate(CCW, returnAngle(stepperMotorAngle) );
						Timers_enu_delay_ms(delay);
					}
		/****************************** Servo Motor Section **************************************/
				}else if(order == '3'){
					LCD_enu_Clear();
					LCD_enu_SendString("Enter Angle:");
					u8 servoMotorAngle[3],angleCounter = 0 ;
					// Display and Storing Angle
					while(angleCounter!=3){
						Keypad_enu_getKey(&key);
						if(key != KEYPAD_U8_NO_KEY_PRESSED && key != '='){
							LCD_enu_SendChar(key);
							servoMotorAngle[angleCounter] = key;
							angleCounter++;
							Timers_enu_delay_ms(200);
						}else if(key == '=') {
							// if user entered angle of one or two digits
							if(angleCounter==1) {servoMotorAngle[1]  = 'a';break;}
							if(angleCounter==2) {servoMotorAngle[2]  = 'a';break;}
						}
					}
					Servo_enu_SetAngle(returnAngle(servoMotorAngle));
		/********************************************* Exit Section *****************************************/
				}else if (order == '4'){
					LCD_enu_Clear();
					LCD_enu_SendString("Exiting .. ");
					LCD_enu_SetCursor(1, 0);
					LCD_enu_SendString("Stopping Motors");
					Timers_enu_delay_ms(delay);
					LCD_enu_Clear();
					/*Stop All Motors*/
					DC_Motor_enu_Stop(MOTOR1);
					DC_Motor_enu_Stop(MOTOR2);
					STEP_Motor_enu_Stop();
					break;
				}
			}
		}

	}
	return 0;
}
