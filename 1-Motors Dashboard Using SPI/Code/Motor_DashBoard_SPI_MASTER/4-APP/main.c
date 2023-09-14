#include"APP.h"
int main(void){
    APP_Init();
	while(1){
		getPassword();
		if(order == '1'){DCMotor();}
		else if(order == '2'){stepperMotor();}
		else if(order == '3'){servoMotor();}
		else if (order == '4'){stopMotors();}
	}
	return 0;
}
