//#include "WProgram.h" // TODO remove
//
#include "Configuration.h"
#include "Graph.h"
#include "BitmapFont.h"
#include "Printer.h"
#include "Utils.h"

#include "Stripe.h"

Graph::Graph(ILI9341_t3_sk &t, uint8_t stripeCount) {
	tft = &t;
	palettes = NULL;

	addNewStripeCounterMs = 0;
	newStripInMs = variance(NEW_STRIPE_EVERY_MS, NEW_STRIPE_EVERY_MS_VARIATON);

	firstStripe = NULL;
	lastAddedStripe = NULL;

	// Init stripes
	for (int i = 0; i < MAX_STRIPES; i++) {
		stripes[i].Id = i;
	}
}

void Graph::SetPalette(const uint8_t *palette, uint8_t paletteSize, uint8_t alpha_bits) {
	if (palettes) delete palettes;
	palettes = new uint16_t[ALPHA_COUNT*paletteSize]();

	Serialprint("Allocate %d bytes for %d palettes\n", ALPHA_COUNT*paletteSize, ALPHA_COUNT);

	float alphaDiv = 1.0 / (ALPHA_COUNT - 1);

	for (uint8_t alpha = 0; alpha < ALPHA_COUNT; alpha++) {

		alphaToPalette[alpha] = &palettes[alpha*paletteSize];

		for (uint8_t i = 0; i < 16; i++) {
			float multiplier = alphaDiv * alpha;
			byte r = multiplier * palette[3 * i];
			byte g = multiplier * palette[3 * i + 1];
			byte b = multiplier * palette[3 * i + 2];
			uint8_t inv = 15 - i;


			/*Serialprint("Alpha %d color %d,%d,%d ---> %d,%d,%d\n", alpha,
				palette[3 * i],
				palette[3 * i + 1],
				palette[3 * i + 2], r, g, b);*/
			palettes[alpha*paletteSize + inv] = ILI9341_t3::color565(r, g, b);
		}
	}
}

void Graph::SetFont(const BitmapFont &font) {
	this->font = &font;
	glyphs = font.glyphs;
	bitmapData = font.bitmap;
}

void Graph::Tick(word diff) {

	addNewStripeCounterMs += diff;

	if (addNewStripeCounterMs > newStripInMs) {
		newStripInMs = variance(NEW_STRIPE_EVERY_MS, NEW_STRIPE_EVERY_MS_VARIATON);

		addNewStripeCounterMs = 0;
		AddNewStripe();
	}

	Stripe * stripe = firstStripe;
	while (stripe) {
		stripe->Tick(diff);

		// if stripe has ended
		if (!stripe->Active) {
			if (stripe == firstStripe) {
				firstStripe = stripe->Next;
			}
			if (stripe == lastAddedStripe) {
				lastAddedStripe = stripe->Prev;
			}

		}
		stripe = stripe->Next;
	}
}

// TODO improve performance
Stripe* Graph::GetFreeStripe() {
	uint8_t i = 0;
	while (stripes[i].Active == true && i < MAX_STRIPES) 	i++;
	if (i < MAX_STRIPES) return &stripes[i];
	return NULL;
}

void Graph::AddNewStripe() {

#ifdef ROTATED
	float x = -TFT_WIDTH / 10.0f * nextFloat();
	float y = TFT_HEIGHT * nextFloat();
#else
	float x = TFT_WIDTH * nextFloat();
	float y = -TFT_HEIGHT / 10.0f * nextFloat();
#endif

	Stripe *stripe = GetFreeStripe();
	if (!stripe) return;

	stripe->Init(x, y, lastAddedStripe);

	if (!firstStripe) firstStripe = stripe;
	lastAddedStripe = stripe;
}

void Graph::Draw() {
	Stripe *stripe = firstStripe;

	while (stripe) {

		Letter *curLetter = stripe->FirstLetter;
		while (curLetter) {
			DrawGlyph(curLetter->X, curLetter->Y, curLetter->Character, ALPHA_COUNT - 1); // or /2^LAB

			// clear area above if required
			if (!curLetter->letterAbove) {
#ifdef ROTATED
				tft->fillRect(curLetter->LastX, curLetter->Y, (int16_t)curLetter->X - (int16_t)curLetter->LastX, CLEAR_WIDTH, 0x0000);
#else
				tft->fillRect(curLetter->X, curLetter->LastY, CLEAR_WIDTH, (int16_t)curLetter->Y - (int16_t)curLetter->LastY, 0x0000);
#endif
			}
			curLetter = curLetter->next;
		}

		if (stripe->Visible) {
			DrawGlyph(stripe->X, stripe->Y, stripe->MainLetter, ALPHA_COUNT - 1);
		}

		// clear area above if required
		if (!stripe->LetterAbove) {
#ifdef ROTATED
			tft->fillRect(stripe->LastX, stripe->Y, (int16_t)stripe->X - (int16_t)stripe->LastX, CLEAR_WIDTH, 0x0000);
#else
			tft->fillRect(stripe->X, stripe->LastY, CLEAR_WIDTH, (int16_t)stripe->Y - (int16_t)stripe->LastY, 0x0000);
#endif
		}

		//delay(10);
		stripe = stripe->Next;
	}
}


// Draws a glyph at the given position and performs clipping if required
void Graph::DrawGlyph(int16_t x, int16_t y, byte glyphId, byte alpha) {
	byte width			= glyphs[glyphId].width;
	byte nextLineOffset = (width >> 1) + (width % 2); // Ok
	byte height			= glyphs[glyphId].height;
	uint16_t offset = glyphs[glyphId].bitmapOffset;

	if ((x >= 0) && (y >= 0) && (x + width < TFT_WIDTH) && (y + height < TFT_HEIGHT)) {
		// draw full width and height of glyph
		tft->writeRect4BPP(x, y, width, height, &bitmapData[offset], alphaToPalette[alpha]);
	}
	else {
		// some part of the glyph is out of screen
		int16_t tftMaxX = tft->width();
		int16_t tftMaxY = tft->height();
		int16_t x_overlap = max(0, min(tftMaxX, x + width) - max(0, x));
		int16_t y_overlap = max(0, min(tftMaxY, y + height) - max(0, y));
		int16_t pic_ys = max(0, -y);
		int16_t screen_xs = max(x, 0);
		int16_t screen_ys = max(y, 0);

		//not needed
		//int16_t screen_xe = min(x + width, tftMaxX);
		//int16_t screen_ye = min(y + height, tftMaxY);
		if (x_overlap == width && y_overlap > 0) {
			// draw full width of bitmap
			tft->writeRect4BPP(screen_xs, screen_ys, x_overlap, y_overlap, &bitmapData[offset + pic_ys * nextLineOffset], alphaToPalette[alpha]);
		}
		else
		{
			int16_t pic_xs = max(0, -x);
			if (pic_xs % 2 == 0) {
				// EVEN starting with new byte in picture
				int16_t pic_xs2 = (pic_xs >> 1); // use full 8 bits of first bitmapData byte for 2 pixels
				int16_t screen_ysAdd = screen_ys;
				for (int16_t y = pic_ys; y < pic_ys + y_overlap; y++) {
					tft->writeRect4BPP(screen_xs, screen_ysAdd, x_overlap, 1, &bitmapData[offset + y * nextLineOffset + pic_xs2], alphaToPalette[alpha]);
					screen_ysAdd++;
				}

			}
			else {
				// UNEVEN starting with new byte in picture
				int16_t pic_xs2 = (pic_xs >> 1); // use 4 lower bits of first bitmapData byte for first pixel
				int16_t screen_ysAdd = screen_ys;
				for (int16_t y = pic_ys; y < pic_ys + y_overlap; y++) {
					tft->writeRect4BPPstartinghalfByte(screen_xs, screen_ysAdd, x_overlap, 1, &bitmapData[offset + y * nextLineOffset + pic_xs2], alphaToPalette[alpha]);
					screen_ysAdd++;
				}
			}
		}
	}
}

/*
Tests for drawing a glyph on the screen edges
DrawLetter(20, 20, 0, ALPHA_COUNT - 1);
DrawLetter(-5, -5, 0, ALPHA_COUNT - 1);
DrawLetter(110-5, -6, 0, ALPHA_COUNT - 1); // oben mitte
DrawLetter(120, -5, 0, ALPHA_COUNT - 1); // oben mitte
DrawLetter(130+5, -4, 0, ALPHA_COUNT - 1); // oben mitte
DrawLetter(235, -5, 0, ALPHA_COUNT - 1);
DrawLetter(-6, 150-5, 0, ALPHA_COUNT - 1); // links mitte
DrawLetter(-5, 160, 0, ALPHA_COUNT - 1); // links mitte
DrawLetter(-4, 170+5, 0, ALPHA_COUNT - 1); // links mitte
DrawLetter(234, 150-5, 0, ALPHA_COUNT - 1); // rechts mitte
DrawLetter(235, 160, 0, ALPHA_COUNT - 1); // rechts mitte
DrawLetter(236, 170+5, 0, ALPHA_COUNT - 1); // rechts mitte
DrawLetter(-5, 315, 0, ALPHA_COUNT - 1);
DrawLetter(110-5, 314, 0, ALPHA_COUNT - 1);// unten mitte
DrawLetter(120, 315, 0, ALPHA_COUNT - 1);// unten mitte
DrawLetter(130+5, 316, 0, ALPHA_COUNT - 1);// unten mitte
DrawLetter(235, 315, 0, ALPHA_COUNT - 1);
*/
