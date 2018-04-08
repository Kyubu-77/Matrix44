#pragma once
//
#include "Arduino.h"
#include "Configuration.h"

class Letter {

public:
	Letter();
	void Init(float x, float y, char character, float speed, float alfaDecay, Letter * prev);
	void Tick(uint16_t ms);
	
public:
	uint16_t Id;
	boolean Active;
		
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
	

	float speed;
	
	boolean isChangingCharacterLetter;
	uint16_t changeCounter;
	uint16_t changeMS;

	boolean deActiveOnNextTick;
	
	unsigned long  lifeTimeMsCounter;
};

