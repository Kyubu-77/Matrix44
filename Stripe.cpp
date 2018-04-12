#include "Configuration.h"
#include "Stripe.h"
#include "Utils.h"
//
LetterManager Stripe::letterManager;

Stripe::Stripe() {
	Id = 0;
	Active = false;
	MainLetterVisible = true;

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

	stripesAlfaDecayOfLettersMs = 0;

	hasStaticLetters = false;
	staticLettersAfterNthLetters = 0;

	lettersUsed = 0;
	lettersAlive = 0;
}

void Stripe::Init(float x, float y, Stripe * prev) {
	Active = true;
	MainLetterVisible = true;

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

	stripesAlfaDecayOfLettersMs = variance(LETTER_ALPHA_DEGREASE_PER_MS, LETTER_ALPHA_DEGREASE_PER_MS_VARIATON);

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
	if (!letter) {
		Serialprint("Stripe::no letter\n");
		return NULL;
	}

	float alfaDecay = stripesAlfaDecayOfLettersMs;
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
		letter->Init(LetterAbove->X + FONT_HEIGHT, Y, character, stripeSpeed *LETTER_UP_FACTOR_TO_STRIPE_SPEED, alfaDecay, LetterAbove, hasStaticLetters);
#else
		letter->Init(X, letterAbove->Y + FONT_HEIGHT, character, stripeSpeed *LETTER_UP_FACTOR_TO__STRIPE_SPEED, alfaDecay, letterAbove);
#endif
	}
	else
	{
		// first letter appear directly behind the mainletter with an offset (on teensy offset will be used for first erase character)
#ifdef ROTATED
		letter->Init(X + yOffset4firstletter, Y, character, stripeSpeed *LETTER_UP_FACTOR_TO_STRIPE_SPEED, alfaDecay, LetterAbove, hasStaticLetters);
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
	// Stripe deletion
	if (deActiveOnNextTick) {
		if (Next) {
			Next->Prev = Prev;
			//Serialprint("Stripe::Tick Id=%d, set prev of %d to %d\n", Id, Next->Id, Prev->Id);
		}
		if (Prev) {
			Prev->Next = Next;
			//Serialprint("Stripe::Tick Id=%d, set next of %d to %d\n", Id, Prev->Id, Next->Id);
		}
		// don't change the own prev or next to NULL because the caller still needs it for cleanup loop
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

	// Tick letters
	Letter *curLetter = FirstLetter;
	while (curLetter) {
		curLetter->Tick(ms);
		if (!curLetter->Active) {
			// Letter out of screen or fadet out and cleanup rect has been already drawn
			if (curLetter == LetterAbove) LetterAbove = NULL; // Triggers drawing the cleanup rect for the main letter
			if (curLetter == FirstLetter) FirstLetter = curLetter->next;
			lettersAlive--;
		}
		curLetter = curLetter->next;
	}

	// Check if stripe is finished
	if (!hasStaticLetters) {
#ifdef ROTATED
		if (X >= TFT_WIDTH) {
#else
		if (Y >= TFT_HEIGHT) {
#endif
			// if mainletter is out of screen hidemainletter and stop emitting new letters
			emitLetters = false;
			MainLetterVisible = false;

			// stripe keeps aktiv as long as there is a letter
			if (lettersAlive == 0) deActiveOnNextTick = true;
			return;
		}
	}
	else {
		// For static falling letters the stript must keep emitting letters until the first emitted letter is out of screen
#ifdef ROTATED
		if (FirstLetter->X >= TFT_WIDTH + FONT_HEIGHT) {
#else
		if (FirstLetter->Y >= TFT_HEIGHT + FONT_HEIGHT) {
#endif
			emitLetters = false;
			MainLetterVisible = false;

			// Everything should be off screen now, so deactivate all letters manually 
			Letter *curLetter = FirstLetter;
			while (curLetter) {
				//curLetter->deActiveOnNextTick = true;
				curLetter->Active = false;
				curLetter->Alfa = 0; // empty letter, may a tick before the letter was still on screen
				Serialprint("Letter::Tick free letter id %d\n", Id);
				curLetter = curLetter->next;
			}
			deActiveOnNextTick = true;
			return;
		}
	}

	// the main letter may change from time to time
	if (mainLetterChangeCounter > NEW_STRIPE_MAIN_LETTER_EVERY_MS)
	{
		mainLetterChangeCounter %= NEW_STRIPE_MAIN_LETTER_EVERY_MS;
		MainLetter = (nextUInt16() % (MAX_GLYPH - 1)) + 1;
	}

	bool checkLifeTime = false;

	if (emitLetters) {
		if (LetterAbove) {
			// not the first letter
#ifdef ROTATED
			while (X - LetterAbove->X >= FONT_HEIGHT) {
#else
			while (Y - letterAbove->Y >= FONT_HEIGHT) {
#endif
				if (LetterAbove->Character == MainLetter) {
					LetterAbove->Character = (nextUInt16() % (MAX_GLYPH - 1)) + 1; // try to avoid same character below each other
				}

				Letter * newLetter = AddLetterToStripe(MainLetter, 0);
				if (newLetter) {
					checkLifeTime = true;
					LetterAbove = newLetter;
					if (!FirstLetter) FirstLetter = newLetter;
				}
				else {
					// running out of letters 
					break; 
					// this does not stop the animation, but sadly this means some graphic errors
					// in order to avoid this increase the MAX_LETTERS constants or change the letter buffer to 
					// dynamic allocation of letters (with the risk of defragmenting the memory)
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
		if (checkLifeTime && (lifeTimeMsCounter > maxLifeTimeMs)) {
			if (!hasStaticLetters || (hasStaticLetters && lettersUsed > staticLettersAfterNthLetters)) {


				emitLetters = false;
				MainLetterVisible = false;

				// stripe it keps as long as there is a letter
				if (lettersAlive == 0) {
					deActiveOnNextTick = true;
				}
				return;
			}
		}
	}
}


