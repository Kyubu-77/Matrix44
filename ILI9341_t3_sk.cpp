#include <SPI.h>
#include "ILI9341_t3_sk.h"

#define SPICLOCK 30000000

// writeRect4BPP - 	write 4 bit per pixel paletted bitmap starting with the 4 highest bits for first byte in bitmap data
//					bitmap data in array at pixels, 4 bits per pixel
//					color palette data in array at palette
//					width must be at least 2 pixels
// overwrite orignial impl to support uneven widths
void ILI9341_t3_sk::writeRect4BPP(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pixels, const uint16_t * palette)
{
	SPI.beginTransaction(SPISettings(SPICLOCK, MSBFIRST, SPI_MODE0));
	setAddr(x, y, x + w - 1, y + h - 1);
	writecommand_cont(ILI9341_RAMWR);
	for (y = h; y > 0; y--) {
		for (x = w; x > 2; x -= 2) {
			writedata16_cont(palette[((*pixels) >> 4) & 0xF]);
			writedata16_cont(palette[(*pixels++) & 0xF]);
		}

		// support for drawing uneven widths
		if (x == 2) {
			writedata16_cont(palette[((*pixels) >> 4) & 0xF]);
			writedata16_last(palette[(*pixels++) & 0xF]);
		}
		else {
			writedata16_last(palette[((*pixels) >> 4) & 0xF]);
		}
	}
	SPI.endTransaction();
}

// writeRect4BPP - 	write 4 bit per pixel paletted bitmap with the 4 lowest bits for first byte in bitmap data
//					bitmap data in array at pixels, 4 bits per pixel
//					color palette data in array at palette
//					width must be at least 2 pixels
// supports uneven widths
void ILI9341_t3_sk::writeRect4BPPstartinghalfByte(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pixels, const uint16_t * palette)
{
	SPI.beginTransaction(SPISettings(SPICLOCK, MSBFIRST, SPI_MODE0));
	setAddr(x, y, x + w - 1, y + h - 1);
	writecommand_cont(ILI9341_RAMWR);
	for (y = h; y > 0; y--) {

		writedata16_cont(palette[(*pixels++) & 0xF]);

		for (x = w - 1; x > 2; x -= 2) {
			writedata16_cont(palette[((*pixels) >> 4) & 0xF]);
			writedata16_cont(palette[(*pixels++) & 0xF]);
		}

		// support for drawing uneven widths
		if (x == 2) {
			writedata16_cont(palette[((*pixels) >> 4) & 0xF]);
			writedata16_last(palette[(*pixels++) & 0xF]);
		}
		else {
			writedata16_last(palette[((*pixels) >> 4) & 0xF]);
		}
	}
	SPI.endTransaction();
}
