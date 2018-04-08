#pragma once
//

//Teensy ILI9341
#include "ILI9341_t3_sk.h"
const uint16_t TFT_WIDTH = ILI9341_TFTWIDTH;
const uint16_t TFT_HEIGHT = ILI9341_TFTHEIGHT;

//Own 
#include "matrixFont.h"

#define ROTATED 1; // Stripe from left to right

// Font
const int16_t FONT_HEIGHT = Matrix.glyphs[0].height;
const int16_t FONT_WIDTH  = Matrix.glyphs[0].width;
const uint8_t MAX_GLYPH = Matrix.glyphsSize;


const uint8_t PALETTE_SIZE = Matrix.paletteSize;
extern const uint8_t *PALETTE;

const uint16_t ERASE_LETTER_WIDTH = FONT_WIDTH; // space letter required to clear the tail
const BitmapFont USED_FONT = Matrix;

// Stripes
const int8_t MAX_STRIPES			= 15;
const int8_t MAX_LETTERS_FOR_STRIPE = 33;
const int8_t CLEAR_WIDTH			= Matrix.glyphs[0].width; //must match with width of font glyph to avoid artifacts

// Stripe creation
const uint16_t NEW_STRIPE_EVERY_MS				= 200;
const float    NEW_STRIPE_EVERY_MS_VARIATON		= 0.25;
const uint16_t NEW_STRIPE_MAIN_LETTER_EVERY_MS	= 500;

// Stripe movement
const float STIPE_MOVE_PX_PER_MS					= 0.10f;  
const float STIPE_MOVE_PX_PER_MS_VARIATION_PERCENT	= 0.5f;//0.5f;

// Stripe lifetime
const float LIFE_TIME_MS						 = 3000;
const float LIFE_TIME_DISTANCE_VARIATION_PERCENT = 0.3f;

// Stripe letters move slower then stripe itself with mainletter
// = 1  letter move as fast as stripe
// > 1  letter moves faster
// < 1  letter moves slower(use this, new letters are created to fill the gap)
const float LETTER_UP_FACTOR_TO_STRIPE_SPEED = 0.5;

// Stripe letter creation
// Usually if there is space for a new letter the mainletter is cloned, but sometimes 
// just the existing letter fall down one font hight
// If there is space for more than one new letter several letters may be inserted
const float   STATIC_LETTERS_PROBAPILITY				= 0.5f;
const uint8_t STATIC_LETTERS_AFTER_X_LETTERS			= 5;
const float   STATIC_LETTERS_AFTER_X_LETTERS_VARIATON	= 0.0f;

// Letter changing character
const float CHANGING_LETTER_PROBAPILITY = 0.1f;//0.1f;
const float CHANGING_LETTER_MS = 1000.0f;
const float CHANGING_LETTER_MS_VARIATON = 0.2f;

// Letter fading out 
const float LETTER_ALPHA_DEGREASE_AFTER_MS = 2000.0f;
const float LETTER_ALPHA_DEGREASE_PER_MS = 0;
const float LETTER_ALPHA_DEGREASE_PER_MS_VARIATON = 0.3f;

// Letters
const uint16_t MAX_LETTERS = 200;
const uint8_t  LETTER_ALPHA_BITS = 5; // 32 fading steps
const uint8_t  ALPHA_COUNT = (0x1 << LETTER_ALPHA_BITS);
