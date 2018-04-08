#pragma once

typedef struct {
	uint16_t bitmapOffset;     // Pointer into GFXfont->bitmap
	uint8_t  width, height;    // Bitmap dimensions in pixels
	uint8_t  xAdvance;         // Distance to advance cursor (x axis)
	int8_t   xOffset, yOffset; // Dist from cursor pos to UL corner
} Glyph;

typedef struct {
	// palette
	const uint8_t * palette;
	uint8_t paletteSize;

	const uint8_t *bitmap;      // Glyph bitmaps, concatenated
	uint8_t yAdvance;			// Newline distance (y axis)

	const Glyph *glyphs;        // Glyph array
	uint8_t glyphsSize;			// Glyph array size
} BitmapFont;
