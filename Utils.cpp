#include <avr\pgmspace.h>

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
	return (float)(value * variation_factor); // if percent_variation = (0.5) 50% then factor will be between 0.5 and 1.5
}

// Debug output
// thx to http://www.utopiamechanicus.com/article/low-memory-serial-print/
void StreamPrint_progmem(Print &out, PGM_P format, ...)
{
	// program memory version of printf - copy of format string and result share a buffer
	// so as to avoid too much memory use
	char formatString[128], *ptr;
	strncpy_P(formatString, format, sizeof(formatString)); // copy in from program mem
														   // null terminate - leave last char since we might need it in worst case for result's \0
	formatString[sizeof(formatString) - 2] = '\0';
	ptr = &formatString[strlen(formatString) + 1]; // our result buffer...
	va_list args;
	va_start(args, format);
	vsnprintf(ptr, sizeof(formatString) - 1 - strlen(formatString), formatString, args);
	va_end(args);
	formatString[sizeof(formatString) - 1] = '\0';
	out.print(ptr);
}

