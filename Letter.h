#pragma once
//
#include "Arduino.h"
#include "Configuration.h"

class Letter {

public:
	Letter();
	void Init(float x, float y, char character, float speed, float alfaDecay, Letter * prev, boolean highlander);
	void Tick(uint16_t ms);
	
public:
	uint16_t Id;
	bool Active;
		
	float X;
	float Y;
#ifdef ROTATED
	float LastX;
#else
	float LastY;
#endif
	float Alfa;

	Letter *prev;
	Letter *next;
	Letter *letterAbove;
	char Character;
private:
	float alfaDecay;
	
	bool highlander;
	float speed;
	
	bool isChangingCharacterLetter;
	uint16_t changeCounter;
	uint16_t changeMS;
public:
	bool deActiveOnNextTick;
private:
	unsigned long  lifeTimeMsCounter;
};

