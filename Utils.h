#pragma once

#include "Arduino.h"

#define Serialprint(format, ...) StreamPrint_progmem(Serial,PSTR(format),##__VA_ARGS__)
#define Streamprint(stream,format, ...) StreamPrint_progmem(stream,PSTR(format),##__VA_ARGS__)

extern uint16_t nextUInt16();
extern float nextFloat();
extern float variance(float value, float variation_percent);
extern void StreamPrint_progmem(Print &out, PGM_P format, ...);


