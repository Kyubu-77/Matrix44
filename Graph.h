#pragma once

#include "ILI9341_t3_sk.h"

#include "Configuration.h"
#include "Stripe.h"
#include "BitmapFont.h"
//
class Stripe;

class Graph {
public:
	Graph(ILI9341_t3_sk &t, uint8_t stripeCount);

	void SetFont(const BitmapFont &f);
	void SetPalette(const uint8_t *f, uint8_t paletteSize, uint8_t alpha_bits);
		
	void Tick(word diff);
	void Draw();
	
private:
	const BitmapFont *font;
	const Glyph *glyphs;
	const uint8_t *bitmapData;

	ILI9341_t3_sk *tft;
	uint16_t *palettes;
	uint16_t *alphaToPalette[ALPHA_COUNT];

	uint16_t newStripInMs;
	uint16_t addNewStripeCounterMs;

	Stripe *firstStripe;
	Stripe *lastAddedStripe;
	Stripe stripes[MAX_STRIPES];
	
	Stripe *GetFreeStripe();
	void AddNewStripe();
	void DrawGlyph(int16_t x, int16_t y, byte glyphId, byte alpha);
};
