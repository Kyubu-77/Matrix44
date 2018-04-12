#pragma once

typedef struct {
	uint16_t bitmapOffset;     // Offset of Glyph in BitmapFont->bitmap
	uint8_t  width, height;    // Glyph dimensions in pixels
	uint8_t  xAdvance;         // Distance to advance cursor (x axis)
	int8_t   xOffset, yOffset; // Dist from cursor pos to UL corner
} Glyph;

typedef struct {
	const uint8_t * palette;    // Palette in with RGB bytes
	uint8_t paletteSize;		// Size of palette

	const uint8_t *bitmap;      // Glyph bitmaps, concatenated
	uint8_t yAdvance;			// Newline distance (y axis)

	const Glyph *glyphs;        // Glyph array
	uint8_t glyphsSize;			// Glyph array size
} BitmapFont;
