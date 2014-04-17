#ifndef _SOCIALLIB_H_
#define _SOCIALLIB_H_

#include "Arduino.h"

#define L10 0
#define L01 1
#define R10 2
#define R01 3
#define L11 4
#define R11 5
#define INITIAL 6
#define LEFT 7
#define MID 8
#define RIGHT 9

extern int irLed;
extern int irDet0;
extern int irDet1;
extern int irDet2;
extern int irDet3;
extern int minVal;

class MyTime{
private:
	int lastState, position;
	unsigned long leftTime, midTime, rightTime;
	long leftDoorTime, rightDoorTime;
public:
	MyTime(){
		lastState = INITIAL;
		position = MID;
		leftTime = 0; 
		midTime = 0; 
		rightTime = 0; 
		leftDoorTime = 0; 
		rightDoorTime = 0;
	}
	void updateTime();
	void updatePosition();
	void updateState();
	void printTime(int);
	void printPosition(int);
	void printState(int);
}; 

#endif