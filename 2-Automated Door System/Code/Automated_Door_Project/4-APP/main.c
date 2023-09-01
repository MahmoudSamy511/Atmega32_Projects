#include "APP.h"
u8 pass[] = PASSWORD , userPass[PASSWORD_LENGTH] ,Flag =0 ,Index =0,adminFlag =0,option =0;
u16 sensor1Value  = 0,sensor2Value =0;
int main(){
	UART_enu_Init();
	ADC_enu_Init();
	Keypad_enu_Init();
	Servo_enu_Init();
	LCD_enu_Init();
	LCD_enu_SendString("Hi...");
	while(1){checkSide();}
	return 0;
}
void wrongPasswordHandling(void){
	Index = 0;
	Flag = 0;
	LCD_enu_Clear();
	LCD_enu_SendString("Wrong Password!");
	UART_enu_sendString("Wrong Password!");
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
					UART_enu_sendString("Admin Logged IN");
					LCD_enu_SetCursor(1,0);
					LCD_enu_SendString("Door Locked");
					UART_enu_sendString("Door Locked");
					_delay_ms(1000);
					adminFlag = 1;
					option = 0;
					Index= 0;
					break;
				}else if(option == '2'){
					LCD_enu_SetCursor(0,0);
					LCD_enu_SendString("Door UnLocked");
					UART_enu_sendString("Door UnLocked");
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
	UART_enu_sendString("Displaying Options");
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
				UART_enu_sendString("Opening Door..");
				_delay_ms(OPEN_DELAY);
				Servo_enu_SetAngle(CLOSE_ANGLE);
				LCD_enu_Clear();
				LCD_enu_SendString("Closing Door..");
				UART_enu_sendString("Closing Door..");
				_delay_ms(CLOSE_DELAY);
			}
			else if((sensor2Value < IR_RANGE)){
				Servo_enu_SetAngle(OPEN_ANGLE);
				LCD_enu_Clear();
				LCD_enu_SendString("Opening Door..");
				UART_enu_sendString("Opening Door..");
				_delay_ms(OPEN_DELAY);
				Servo_enu_SetAngle(CLOSE_ANGLE);
				LCD_enu_Clear();
				LCD_enu_SendString("Closing Door..");
				UART_enu_sendString("Closing Door..");
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
