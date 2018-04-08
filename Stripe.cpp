#include "Configuration.h"
#include "Stripe.h"
#include "Utils.h"
#include "Printer.h"
//
LetterManager Stripe::letterManager;

Stripe::Stripe() {
	Id = 0;
	Active = false;
	Visible = true;

	X = 0;
	Y = 0;
#ifdef ROTATED
	LastX = X;
#else
	LastY = Y;
#endif
	LetterAbove = NULL;
	FirstLetter = NULL;
	Prev = NULL;
	Next = NULL;
	MainLetter = '#';

	emitLetters = true;
	deActiveOnNextTick = false;
	stripeSpeed = 0;

	mainLetterChangeCounter = 0;
	mainLetterMoved = 0;
	lifeTimeMsCounter = 0;
	maxLifeTimeMs = 0;

	stripesAlfaDecayOfLetters = 0;

	hasStaticLetters = false;
	staticLettersAfterNthLetters = 0;

	lettersUsed = 0;
	lettersAlive = 0;
}

void Stripe::Init(float x, float y, Stripe * prev) {
	Active = true;
	Visible = true;

	X = x; // The mainletter it drawn at this position
	Y = y;
#ifdef ROTATED
	LastX = x;
#else
	LastY = y;
#endif

	LetterAbove = NULL;
	FirstLetter = NULL;
	this->Prev = prev;
	this->Next = NULL;
	MainLetter = (nextUInt16() % (MAX_GLYPH - 1)) + 1;


	emitLetters = true;
	deActiveOnNextTick = false;
	stripeSpeed = variance(STIPE_MOVE_PX_PER_MS, STIPE_MOVE_PX_PER_MS_VARIATION_PERCENT);
	// Serialprint("Stripe::Init id %d at x %f y %f speed %f\n", Id, x, y, stripeSpeed);

	mainLetterChangeCounter = 0;
	mainLetterMoved = 0;

	lifeTimeMsCounter = 0;
	maxLifeTimeMs = (unsigned long)variance(LIFE_TIME_MS, LIFE_TIME_DISTANCE_VARIATION_PERCENT);

	stripesAlfaDecayOfLetters = variance(LETTER_ALPHA_DEGREASE_PER_MS, LETTER_ALPHA_DEGREASE_PER_MS_VARIATON);

	hasStaticLetters = nextFloat() < STATIC_LETTERS_PROBAPILITY;
	staticLettersAfterNthLetters = variance(STATIC_LETTERS_AFTER_X_LETTERS, STATIC_LETTERS_AFTER_X_LETTERS_VARIATON);

	lettersUsed = 0;
	lettersAlive = 0;

	if (prev) {
		prev->Next = this;
	}
}

Letter * Stripe::AddLetterToStripe(char character, int16_t yOffset4firstletter) {
	Letter *letter = Stripe::letterManager.GetFreeLetter();
	if (!letter) return NULL;

	float alfaDecay = stripesAlfaDecayOfLetters;
	if (hasStaticLetters)
	{
		if (lettersUsed > staticLettersAfterNthLetters)
		{
			// just slide the letters down from now on
			Letter * l = FirstLetter;
			while (l) {
#ifdef ROTATED
				l->X += FONT_HEIGHT;
#else
				l->Y += FONT_HEIGHT;
#endif
				l = l->next;
			}
			return NULL;
		}

		// static letters don't fade out, but still there is the first erase letter
		alfaDecay = 0.0f;
	}

	if (LetterAbove)
	{
		// non first letter appear with normal linespace below the last created letter (looks better), this may be behind the main letter
#ifdef ROTATED
		letter->Init(LetterAbove->X + FONT_HEIGHT, Y, character, stripeSpeed *LETTER_UP_FACTOR_TO_STRIPE_SPEED, alfaDecay, LetterAbove);
#else
		letter->Init(X, letterAbove->Y + FONT_HEIGHT, character, stripeSpeed *LETTER_UP_FACTOR_TO__STRIPE_SPEED, alfaDecay, letterAbove);
#endif
	}
	else
	{
		// first letter appear directly behind the mainletter with an offset (on teensy offset will be used for first erase character)
#ifdef ROTATED
		letter->Init(X + yOffset4firstletter, Y, character, stripeSpeed *LETTER_UP_FACTOR_TO_STRIPE_SPEED, alfaDecay, LetterAbove);
#else
		letter->Init(X, Y + yOffset4firstletter, character, stripeSpeed *LETTER_UP_FACTOR_TO__STRIPE_SPEED, alfaDecay, letterAbove);
#endif
	}

	lettersUsed++;
	lettersAlive++;

	return letter;
}

void Stripe::Tick(uint16_t ms)
{
	if (deActiveOnNextTick) {
		if (Next) {
			Next->Prev = Prev;
			//Serialprint("Stripe::Tick Id=%d, set prev of %d to %d\n", Id, Next->Id, Prev->Id);
		}
		if (Prev) {
			Prev->Next = Next;
			//Serialprint("Stripe::Tick Id=%d, set next of %d to %d\n", Id, Prev->Id, Next->Id);
		}
		// don't the own prev or next to NULL because the caller still needs it.
		Active = false;
		return;
	}

	// Tick stripe
#ifdef ROTATED
	LastX = X;
	X += stripeSpeed * ms;
#else
	LastY = Y;
	Y += stripeSpeed * ms;
#endif

	lifeTimeMsCounter += ms;
	mainLetterChangeCounter += ms;
	mainLetterMoved += stripeSpeed * ms;

	// Letter tick
	Letter *curLetter = FirstLetter;
	while (curLetter) {
		curLetter->Tick(ms);

		// Letter out of screen or fadet out
		if (!curLetter->Active) {
			if (curLetter == LetterAbove)  LetterAbove = NULL; // Triggers drawing the cleanup rect
			if (curLetter == FirstLetter)  FirstLetter = curLetter->next;
			lettersAlive--;
		}

		curLetter = curLetter->next;
	}

	// main letter is off screen or ended
#ifdef ROTATED
	if ((X >= TFT_WIDTH)) {
#else
	if ((Y >= TFT_HEIGHT)) {
#endif
		emitLetters = false;
		Visible = false;

		// stripe it keeps aktiv as long as there is a letter
		if (lettersAlive == 0) deActiveOnNextTick = true;
		return;
	}

	// the main letter may change from time to time
	if (mainLetterChangeCounter > NEW_STRIPE_MAIN_LETTER_EVERY_MS)
	{
		mainLetterChangeCounter %= NEW_STRIPE_MAIN_LETTER_EVERY_MS;
		MainLetter = (nextUInt16() % (MAX_GLYPH - 1)) + 1;
	}
	
	// if there is enought space between the last letter and the last letter // add loop for fast stripe 2 letter may have to be inserted
	bool checkLifeTime = false;

	if (emitLetters) {
		if (LetterAbove) {
#ifdef ROTATED
			while (X - LetterAbove->X >= FONT_HEIGHT)
#else
			while (Y - letterAbove->Y >= FONT_HEIGHT)
#endif
			{

				if (LetterAbove->Character == MainLetter) {
					LetterAbove->Character = (nextUInt16() % (MAX_GLYPH - 1)) + 1; // try to avoid same character below each other
				}

				Letter * newLetter = AddLetterToStripe(MainLetter, 0);
				if (newLetter) {
					checkLifeTime = true;
					LetterAbove = newLetter;
					if (!FirstLetter) FirstLetter = newLetter;
				}
			}
		}
		else
		{
			while (mainLetterMoved > FONT_HEIGHT) // while because the may be space for several letters
			{
				// main char moved more then a letter i height
				Letter * newLetter = AddLetterToStripe(MainLetter, 0);

				if (newLetter) {
					checkLifeTime = true;
					LetterAbove = newLetter;
					if (!FirstLetter) FirstLetter = newLetter;
				}
				mainLetterMoved -= FONT_HEIGHT;
			}
		}


		// Stop the stripes Mainletter movement, just at the point if a new letter has been emitted
		if (checkLifeTime && (hasStaticLetters && lettersUsed > staticLettersAfterNthLetters)) {
			if (lifeTimeMsCounter > maxLifeTimeMs) {

				emitLetters = false;
				Visible = false;

				// Hide mainletter immeatedely, last emitted letter is still shown
				//
				/*if (MainLetter != ERASE_LETTER) {
					// this tick --> delete MainLetter on screen
					MainLetter = ERASE_LETTER;
				}
				else {
					// next tick --> don't render MainLetter
					visible = false;
				}*/

				// stripe it keps as long as there is a letter
				if (lettersAlive == 0) {
					deActiveOnNextTick = true;
				}
				return;
			}
		}
	}
}

