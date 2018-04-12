#pragma once
//
#include "Configuration.h"
#include "Letter.h"
#include "Utils.h"

class LetterManager {

public:
	LetterManager() {
		uint16_t  i = 0;
		while (i < MAX_LETTERS) { 
			letterBuffer[i].Id = i; 
			i++;
		};
	}

	Letter * GetFreeLetter() {
		for (uint16_t i = 0; i < MAX_LETTERS; i++) {
			if (!letterBuffer[i].Active) return  &letterBuffer[i];
		}
		// ok,
		return NULL;
	}

private:
	Letter letterBuffer[MAX_LETTERS];
};