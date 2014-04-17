#include "SocialLib.h"

int irLed = 2;
int irDet0 = 0;
int irDet1 = 1;
int irDet2 = 2;
int irDet3 = 3;
int minVal = 800;
MyTime T;

void setup() {
	Serial.begin(38400);
	pinMode(irLed, OUTPUT);
	digitalWrite(irLed,HIGH);
}

void loop (){

	T.updateState();
	T.updateTime();

}
