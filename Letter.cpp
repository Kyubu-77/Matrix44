#include "Configuration.h"
#include "Letter.h"
#include "Utils.h"
#include "Printer.h"
//
Letter::Letter()
{
	Id = 0;
	Active = false;
	X = 0;
	Y = 0;
#ifdef ROTATED
	LastX = X;
#else
	LastY = Y;
#endif
	Alfa = 0;

	prev = NULL;
	next = NULL;
	Character = '#';
	letterAbove = NULL;

	
	alfaDecay = 0;
	
	speed = 0;

	isChangingCharacterLetter = false;
	changeCounter = 0;
	changeMS = 0;

	deActiveOnNextTick = false;

	lifeTimeMsCounter = 0;
}

void Letter::Init(float x, float y, char character, float speed, float alfaDecay, Letter * prev) {
	Serialprint("Letter::Init id %d at x %f y %f speed %f\n", Id, x, y, speed);
	Active = true;
	this->X = x;
	this->Y = y;
#ifdef ROTATED
	LastX = 0;
#else
	LastY = 0;
#endif

	Alfa = 255.0f;

	this->prev = prev;
	if (prev) prev->next = this;
	next = NULL;
	this->Character = character;
	this->letterAbove = prev;
	

	this->alfaDecay = alfaDecay;
	
	this->speed = speed;

	isChangingCharacterLetter = false;
	changeCounter = 0;
	changeMS = 0;

	deActiveOnNextTick = false;

	lifeTimeMsCounter = 0;

	if (nextFloat() < CHANGING_LETTER_PROBAPILITY) {
		isChangingCharacterLetter = true;
		changeMS = variance(CHANGING_LETTER_MS, CHANGING_LETTER_MS_VARIATON);
	}
}

void Letter::Tick(uint16_t ms) {
	if (deActiveOnNextTick) {
		// relink Letters
		if (next) {
			next->letterAbove = NULL; // Triggers drawing the cleanup rect
			next->prev = prev;
		}
		if (prev) {
			prev->next = next;
		}
		Serialprint("Letter::Tick free letter id %d", Id);
		Active = false;
		return;
	}

#ifdef ROTATED
	LastX = X;
	X += speed * ms;
#else
	LastY = Y;
	Y += speed * ms;
#endif

	lifeTimeMsCounter += ms;

	if (isChangingCharacterLetter)
	{
		changeCounter += ms;
		if (changeCounter > changeMS)
		{
			changeCounter %= changeMS;
			Character = (nextUInt16() % (MAX_GLYPH - 1)) + 1;
		}
	}

	if (lifeTimeMsCounter > LETTER_ALPHA_DEGREASE_AFTER_MS)
	{
		Alfa -= alfaDecay;
	}

#ifdef ROTATED
	if (X >= TFT_WIDTH || Alfa < 0)
#else
	if (Y >= TFT_HEIGHT || Alfa < 0)
#endif
	{
		// keep the letter active for the next draw step, this is requried for screen cleanup with a black letter
		deActiveOnNextTick = true;
	}
}