#pragma once
//
#include "Configuration.h"
#include "LetterManager.h"
#include "Letter.h"

class Stripe
{
	
public:
	Stripe();
	void Init(float x, float y, Stripe * prev);
	void Tick(uint16_t ms);

private:
	Letter * AddLetterToStripe(char character, int16_t yOffset4firstletter);
	

public:	
	uint16_t Id;
	boolean Active; // stripes lifetime is over or letter the screen
	boolean Visible;
		
	float X;
	float Y;
#ifdef ROTATED
	float LastX;
#else
	float LastY;
#endif

	Letter *LetterAbove; // the letter directly over the mainletter (=last created letter)
	Letter *FirstLetter;

	Stripe *Prev;
	Stripe *Next;
	char	MainLetter;		// the letter which is alway the lowest on the stripe
private:
	
	boolean emitLetters;
	boolean deActiveOnNextTick;
	float stripeSpeed;

	
	uint16_t mainLetterChangeCounter; // the mainletter changes the shown char for better effect
	float  mainLetterMoved;
	unsigned long lifeTimeMsCounter;
	unsigned long maxLifeTimeMs;

	float stripesAlfaDecayOfLetters; // only for non static letters

	boolean hasStaticLetters;
	uint16_t staticLettersAfterNthLetters;
		
	uint8_t lettersUsed;
	uint8_t lettersAlive;
	
	static LetterManager letterManager;
};

