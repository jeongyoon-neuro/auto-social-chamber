#include "SocialLib.h"

int irLed = 2;
int buttonPin = 3;
int irDet0 = 0;
int irDet1 = 1;
int irDet2 = 2;
int irDet3 = 3;
int minVal = 800;
int buttonState = 0;
int lastButtonState=0;
MyTime T;

void setup() {
	Serial.begin(38400);
	pinMode(irLed, OUTPUT);
	pinMode(buttonPin, INPUT);
	digitalWrite(irLed,HIGH);
	
}

void loop (){

	updateSwitch();
	while (buttonState == HIGH)
	{
	T.updateState();
	T.updateTime();
//	updateSwitch();
	}

}
