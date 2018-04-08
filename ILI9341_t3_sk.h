#pragma once

#include "ILI9341_t3.h"
class ILI9341_t3_sk : public ILI9341_t3
{
public:
	ILI9341_t3_sk(uint8_t _CS, uint8_t _DC, uint8_t _RST = 255, uint8_t _MOSI = 11, 
		uint8_t _SCLK = 13, uint8_t _MISO = 12) :
		ILI9341_t3(_CS, _DC, _RST, _MOSI, _SCLK, _MISO) {
	};
	
	void writeRect4BPP(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pixels, const uint16_t * palette);
	void writeRect4BPPstartinghalfByte(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pixels, const uint16_t * palette);
};
