#include"../1-MCAL/ADC/ADC_Interface.h"
#include"../2-HAL/Keypad/Keypad_Interface.h"
#include"../2-HAL/LCD/LCD_Interface.h"
#include"../2-HAL/Servo_Motor/Servo_Interface.h"

#define F_CPU  16000000UL
#include<util/delay.h>

#define IR_RANGE    	300
#define OPEN_DELAY   	1500
#define CLOSE_DELAY   	1000
#define OPEN_ANGLE      90
#define CLOSE_ANGLE      0
/***********************************************************/
#define PASSWORD     		"12345"
#define PASSWORD_LENGTH     5
/***********************************************************/
void wrongPasswordHandling(void);
void getUserPassword(void);
void displayOptionsAndGetUserOption(void);
void checkSide(void);
/***********************************************************/
u8 pass[] = PASSWORD , userPass[PASSWORD_LENGTH] ,Flag =0 ,Index =0,adminFlag =0,option =0;
u16 sensor1Value  = 0,sensor2Value =0;
int main(){
	ADC_enu_Init();
	Keypad_enu_Init();
	Servo_enu_Init();
	LCD_enu_Init();
	LCD_enu_SendString("Hi...");
	while(1){
		checkSide();
	}
	return 0;
}
/**********************************************************************/
void wrongPasswordHandling(void){
	Index = 0;
	Flag = 0;
	LCD_enu_Clear();
	LCD_enu_SendString("Wrong Password!");
	_delay_ms(1000);
	LCD_enu_Clear();
	LCD_enu_SendString("Enter Password:");
	LCD_enu_SetCursor(1,0);
}
void getUserPassword(void){
	LCD_enu_Clear();
	LCD_enu_SendString("Enter Password:");
	LCD_enu_SetCursor(1,0);
	while(1){
		u8 key =0;
		Keypad_enu_getKey(&key);
		if((key != KEYPAD_U8_NO_KEY_PRESSED) && (key != '=')){
			LCD_enu_SendChar('*');
			userPass[Index] =key;
			Index++;
		}else if(key == '='){
			if(Index == PASSWORD_LENGTH){
				for(u8 i = 0;i< PASSWORD_LENGTH;i++){
					if(pass[i]!=userPass[i]){
						Flag = 1;
						break;
					}
				}
			}else{
				wrongPasswordHandling();
			}
			if(Flag){
				wrongPasswordHandling();
			}else if ((!Flag)&&(Index == PASSWORD_LENGTH)){
				LCD_enu_Clear();
				if(option == '1'){
					LCD_enu_SendString("Welcome, User :)");
					LCD_enu_SetCursor(1,0);
					LCD_enu_SendString("Door Locked");
					_delay_ms(1000);
					adminFlag = 1;
					option = 0;
					Index= 0;
					break;
				}else if(option == '2'){
					LCD_enu_SetCursor(0,0);
					LCD_enu_SendString("Door UnLocked");
					_delay_ms(1000);
					option = 0;
					adminFlag = 0;
					Index= 0;
					break;
				}
			}
		}
	}
}
void displayOptionsAndGetUserOption(void){
	LCD_enu_Clear();
	LCD_enu_SendString("1-Lock Door");
	LCD_enu_SetCursor(1,0);
	LCD_enu_SendString("2-UnLock Door");
	while((option!= '1') && (option!= '2')){Keypad_enu_getKey(&option);}
	getUserPassword();
}
void checkSide(void){
	Keypad_enu_getKey(&option);
	while(option == KEYPAD_U8_NO_KEY_PRESSED){
		if(!adminFlag){
		ADC_enu_GetDigitalValueSynchNonBlocking(ADC_U8_CHANNEL0, &sensor1Value);
		ADC_enu_GetDigitalValueSynchNonBlocking(ADC_U8_CHANNEL7, &sensor2Value);
		if((sensor1Value < IR_RANGE)){
				Servo_enu_SetAngle(OPEN_ANGLE);
				LCD_enu_Clear();
				LCD_enu_SendString("Opening Door..");
				_delay_ms(OPEN_DELAY);
				Servo_enu_SetAngle(CLOSE_ANGLE);
				LCD_enu_Clear();
				LCD_enu_SendString("Closing Door..");
				_delay_ms(CLOSE_DELAY);
			}
			else if((sensor2Value < IR_RANGE)){
				Servo_enu_SetAngle(OPEN_ANGLE);
				LCD_enu_Clear();
				LCD_enu_SendString("Opening Door..");
				_delay_ms(OPEN_DELAY);
				Servo_enu_SetAngle(CLOSE_ANGLE);
				LCD_enu_Clear();
				LCD_enu_SendString("Closing Door..");
				_delay_ms(CLOSE_DELAY);
			}
			Keypad_enu_getKey(&option);
		}
		else{
			displayOptionsAndGetUserOption();
		}
	}
	if(option == 'C')
		displayOptionsAndGetUserOption();
}
