#include "Utils.h"

uint16_t nextUInt16() {
	return random(0xFFFF);
}

float nextFloat() {
	return random(100000)/ 100000.0f;
}

float variance(float value, float variation_percent) {
	float rndMinusOneToOne = (2 * nextFloat() - 1.0);
	float variation_factor = 1 + variation_percent * rndMinusOneToOne;
	// if percent_variation = (0.5) 50% then factor will be between 0.5 and 1.5
	return (float)(value * variation_factor);
}

