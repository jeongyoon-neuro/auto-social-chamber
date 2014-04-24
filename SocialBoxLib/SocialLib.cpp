#include "Arduino.h"
#include "SocialLib.h"

void MyTime::printState(int currentState)
{
	switch (currentState){
	case L10:
		Serial.println("L10");
	case L01:
		Serial.println("L01");
	case R10:
		Serial.println("R10");
	case R01:
		Serial.println("R01");
	}
}
void MyTime::printPosition(int currentPosition)
{
	switch (currentPosition)
	{
	case LEFT:
		Serial.println("LEFT");
	case MID:
		Serial.println("MID");
	case RIGHT:
		Serial.println("RIGHT");
	}
}
void MyTime::updateTime()
{
	int tempState = lastState;
	int tempPosition = position;
	unsigned long enterTime, currentTime, elapsedTime;
	enterTime = micros();
	while (tempPosition==position){
		updateState();
		currentTime = micros();
		elapsedTime = currentTime - enterTime;
	}

	updateSwitch();
	if (buttonState != HIGH)
		return;

	if (tempPosition == LEFT)
		leftTime += elapsedTime;
	else if (tempPosition == MID)
		midTime += elapsedTime;
	else if (tempPosition == RIGHT)
		rightTime += elapsedTime;
	printTime(tempPosition);
	Serial.println();
}

void MyTime::printTime(int pos)
{
	double tempTime;
	if (pos == LEFT){
		tempTime = (double)leftTime/1000000;
		Serial.print("Left elapsed: ");
		Serial.print(tempTime);
	//	Serial.print(" ");
	//	Serial.print(leftTime);
	}
	if (pos == MID){
		tempTime = (double)midTime/1000000;
		Serial.print("Mid elapsed: ");
		Serial.print(tempTime);
		//Serial.print(" ");
		//Serial.print(midTime);
	}
	if (pos == RIGHT){
		tempTime = (double)rightTime/1000000;
		Serial.print("Right elapsed: ");
		Serial.print(tempTime);
	//	Serial.print(" ");
	//	Serial.print(rightTime);
	}
}

void MyTime::updateState()
{
	int val0, val1, val2, val3;
	val0 = analogRead(irDet0);
	val1 = analogRead(irDet1);
	val2 = analogRead(irDet2);
	val3 = analogRead(irDet3);
	if (val0<minVal && val1>minVal){
		lastState = L01;
	}
	else if (val0>minVal && val1<minVal){
		lastState = L10;
	}
	else if (val2<minVal && val3>minVal){
		lastState = R01;
	}
	else if (val2>minVal && val3<minVal){
		lastState = R10;
	}
	/*else if (val0>minVal && val1 > minVal){
		lastState = L11;
	}
	else if (val2 > minVal && val3 > minVal){
		lastState = R11;
	}*/
	updatePosition();
}

void MyTime::updatePosition()
{
	if (lastState == L10)
		position = LEFT;
	else if (lastState == L01 || lastState == R10)
		position = MID;
	else if (lastState == R01)
		position = RIGHT;
	else if (lastState == INITIAL)
		position = MID;
}

void updateSwitch()
{
	buttonState = digitalRead(buttonPin);
	if (buttonState == HIGH){
	 Serial.print(buttonState);
	 Serial.println("ON!");}
 
 else{
	 Serial.print(buttonState);
	 Serial.println("OFF!");}

 delay(300);
}