#pragma once
//
#include "Configuration.h"
#include "Letter.h"

class LetterManager {

public:
	LetterManager() {
	}

	Letter * GetFreeLetter() {
		byte i = 0;
		while (letterBuffer[i].Active  && i < MAX_LETTERS) {
			i++;
		}

		if (i < MAX_LETTERS) {
			return &letterBuffer[i];
		}
		return NULL;
	}

private:
	Letter letterBuffer[MAX_LETTERS];
};