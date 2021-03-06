#pragma once

#include "BitmapFont.h"

// R, G, B
const uint8_t Matrix_Palette[] = {
0x00,0xFF,0x00,   // Background
0x00,0xEE,0x00,
0x00,0xDD,0x00,
0x00,0xCC,0x00,
0x00,0xBB,0x00,
0x00,0xAA,0x00,
0x00,0x99,0x00,
0x00,0x88,0x00,
0x00,0x77,0x00,
0x00,0x66,0x00,
0x00,0x55,0x00,
0x00,0x44,0x00,
0x00,0x33,0x00,
0x00,0x22,0x00,
0x00,0x11,0x00,
0x00,0x00,0x00   // Foreground
};

// Array of halfbytes containing the palette entry of the font

const uint8_t Matrix_BitmapData[] PROGMEM = {
    // A
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xBD,0xD0,
    0x00,0x00,0xCD,0xDC,0x00,0x00,
    0x00,0xDF,0x00,0x0F,0x00,0x00,
    0x00,0xFD,0xFD,0x0F,0x00,0x00,
    0x00,0x00,0x00,0xFC,0xFC,0x00,
    0x00,0x00,0x00,0x00,0x00,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // B
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xDD,0x0B,0xDD,0x00,
    0x00,0xC0,0x00,0xF0,0x00,0xF0,
    0x00,0xD0,0x00,0xB0,0x00,0xD0,
    0x00,0xD0,0x00,0xD0,0x00,0xD0,
    0x00,0xE0,0x00,0xB0,0x00,0xD0,
    0x00,0xCD,0xFC,0xFF,0xDD,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // C
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFD,0x00,0x00,0x0E,0xD0,
    0x00,0xD0,0x00,0x00,0x00,0xD0,
    0x00,0xC0,0x00,0x00,0x00,0xF0,
    0x00,0x0D,0xD0,0x00,0xDD,0x00,
    0x00,0x00,0xDF,0xDD,0xD0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // D
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xEB,0xDB,0xF0,0x00,
    0x00,0x0D,0xB0,0x00,0x0E,0x00,
    0x00,0xFF,0x00,0x00,0x00,0xF0,
    0x00,0xBB,0x00,0x00,0x00,0xC0,
    0x00,0xFB,0xFC,0xDE,0xFD,0xC0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // E
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xF0,0x00,0xD0,0x00,0xF0,
    0x00,0xB0,0x00,0xB0,0x00,0xF0,
    0x00,0xD0,0x00,0xE0,0x00,0xD0,
    0x00,0xF0,0x00,0xE0,0x00,0xB0,
    0x00,0xDC,0xDD,0xDD,0xDC,0xC0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // F
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xC0,0x00,0x00,0x00,0x00,
    0x00,0xF0,0x00,0xF0,0x00,0x00,
    0x00,0xC0,0x00,0xD0,0x00,0x00,
    0x00,0xD0,0x00,0xE0,0x00,0x00,
    0x00,0xDF,0xEF,0xDD,0xDD,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // G
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0F,0x00,0xFD,0xDD,0xF0,
    0x00,0xC0,0x00,0xC0,0x00,0xD0,
    0x00,0xF0,0x00,0xD0,0x00,0xD0,
    0x00,0xF0,0x00,0x00,0x00,0xB0,
    0x00,0x0D,0xC0,0x00,0xBC,0x00,
    0x00,0x00,0xCC,0xBC,0xD0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // H
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xDD,0xED,0xEB,0xED,0xC0,
    0x00,0xCD,0xFD,0xDF,0xED,0xD0,
    0x00,0x00,0x00,0xF0,0x00,0x00,
    0x00,0x00,0x00,0xD0,0x00,0x00,
    0x00,0x00,0x00,0xE0,0x00,0x00,
    0x00,0xFD,0xED,0xDD,0xFD,0xE0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // I
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xF0,0x00,0x00,0x00,0xD0,
    0x00,0xED,0xFD,0xFD,0xEF,0xE0,
    0x00,0xB0,0x00,0x00,0x00,0xB0,
    0x00,0xC0,0x00,0x00,0x00,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // J
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xEB,0xDC,0xDB,0xBB,0xD0,
    0x00,0x00,0x00,0x00,0x00,0xB0,
    0x00,0x00,0x00,0x00,0x00,0xF0,
    0x00,0x00,0x00,0x00,0xDD,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // K
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xF0,
    0x00,0xF0,0x00,0x00,0x00,0xD0,
    0x00,0xDE,0x00,0x00,0x0C,0x00,
    0x00,0x00,0xC0,0x00,0xD0,0x00,
    0x00,0x00,0x0F,0xCD,0x00,0x00,
    0x00,0x00,0x0D,0xF0,0x00,0x00,
    0x00,0xDE,0xEC,0xCD,0xDE,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // L
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xE0,
    0x00,0x00,0x00,0x00,0x00,0xE0,
    0x00,0x00,0x00,0x00,0x00,0xD0,
    0x00,0x00,0x00,0x00,0x00,0xD0,
    0x00,0x00,0x00,0x00,0x00,0xF0,
    0x00,0xBE,0xDB,0xDD,0xDD,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // M
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xDD,0xDC,0xBD,0xFC,0xB0,
    0x00,0xDF,0xD0,0x00,0x00,0x00,
    0x00,0x00,0x0C,0xDD,0x00,0x00,
    0x00,0x00,0xEF,0xE0,0x00,0x00,
    0x00,0xCE,0xD0,0x00,0x00,0x00,
    0x00,0xDF,0xDD,0xDE,0xFF,0xB0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // N
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFB,0xDF,0xDB,0xBB,0xE0,
    0x00,0x00,0x00,0x00,0xBC,0xE0,
    0x00,0x00,0x00,0xFD,0xF0,0x00,
    0x00,0x00,0xCC,0xE0,0x00,0x00,
    0x00,0xBF,0xD0,0x00,0x00,0x00,
    0x00,0xBD,0xCE,0xBF,0xDC,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // O
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0F,0xDD,0xFF,0xFD,0x00,
    0x00,0xCD,0x00,0x00,0x0D,0xD0,
    0x00,0xC0,0x00,0x00,0x00,0xF0,
    0x00,0xE0,0x00,0x00,0x00,0xD0,
    0x00,0x0D,0xD0,0x00,0xEE,0x00,
    0x00,0x00,0xFC,0xFD,0xF0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // P
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xDC,0x00,0x00,0x00,
    0x00,0xDB,0x0E,0xC0,0x00,0x00,
    0x00,0xF0,0x00,0xD0,0x00,0x00,
    0x00,0xF0,0x00,0xF0,0x00,0x00,
    0x00,0xD0,0x00,0xD0,0x00,0x00,
    0x00,0xFF,0xDD,0xFB,0xED,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // Q
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xD0,
    0x00,0x00,0xBD,0xED,0xDD,0xE0,
    0x00,0x0F,0x00,0x0C,0xEC,0x00,
    0x00,0xD0,0x00,0xDD,0x0D,0x00,
    0x00,0xD0,0x00,0xF0,0x0B,0x00,
    0x00,0x0D,0xB0,0x0C,0xD0,0x00,
    0x00,0x00,0xED,0xDF,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // R
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xB0,
    0x00,0x0F,0xEF,0x00,0x0E,0xD0,
    0x00,0xD0,0x00,0xBF,0xB0,0x00,
    0x00,0xD0,0x00,0xD0,0x00,0x00,
    0x00,0xF0,0x00,0xE0,0x00,0x00,
    0x00,0xDD,0xDF,0xDD,0xDD,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // S
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xDC,0x00,0x0E,0xEB,0x00,
    0x00,0xB0,0x00,0xF0,0x00,0xF0,
    0x00,0xD0,0x0F,0xF0,0x00,0xE0,
    0x00,0xFF,0xEE,0x00,0x0D,0xC0,
    0x00,0x0F,0xF0,0x00,0xFD,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // T
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xD0,0x00,0x00,0x00,0x00,
    0x00,0xB0,0x00,0x00,0x00,0x00,
    0x00,0xDC,0xFB,0xFC,0xBE,0xD0,
    0x00,0xBD,0xDB,0xDD,0xCD,0xD0,
    0x00,0xD0,0x00,0x00,0x00,0x00,
    0x00,0xF0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // U
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFD,0xDD,0xCC,0xDE,0x00,
    0x00,0x00,0x00,0x00,0x0C,0xD0,
    0x00,0x00,0x00,0x00,0x00,0xD0,
    0x00,0x00,0x00,0x00,0x00,0xF0,
    0x00,0x00,0x00,0x00,0x0B,0xE0,
    0x00,0xED,0xDF,0xEF,0xDD,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // V
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xF0,0x00,0x00,0x00,0x00,
    0x00,0xCF,0xDE,0x00,0x00,0x00,
    0x00,0x00,0x00,0xCF,0xFD,0x00,
    0x00,0x00,0x00,0x00,0x0F,0xC0,
    0x00,0x00,0x00,0x0D,0xDE,0xD0,
    0x00,0x0E,0xFD,0xC0,0x00,0x00,
    0x00,0xC0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // W
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFF,0xDD,0xCC,0xFC,0x00,
    0x00,0x00,0x00,0x00,0xDF,0xB0,
    0x00,0x00,0x00,0xEC,0xB0,0x00,
    0x00,0x00,0x00,0x0D,0xEE,0x00,
    0x00,0x00,0x00,0x0E,0xBD,0xF0,
    0x00,0xCD,0xDD,0xDD,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // X
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFF,0x00,0x00,0x0D,0xE0,
    0x00,0x0E,0xE0,0x0C,0xFE,0x00,
    0x00,0x00,0x0B,0xFF,0x00,0x00,
    0x00,0x00,0xDD,0x0D,0xC0,0x00,
    0x00,0xEF,0x00,0x00,0xBD,0xD0,
    0x00,0xC0,0x00,0x00,0x00,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // Y
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFF,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xCD,0x00,0x00,0x00,
    0x00,0x00,0x0B,0xFC,0xFF,0xF0,
    0x00,0x00,0xBD,0x00,0x00,0x00,
    0x00,0xDC,0x00,0x00,0x00,0x00,
    0x00,0xD0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // Z
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFE,0x00,0x00,0x00,0xD0,
    0x00,0xFC,0xDB,0x00,0x00,0xC0,
    0x00,0xD0,0x0E,0xDD,0x00,0xD0,
    0x00,0xC0,0x00,0x0C,0xBD,0xF0,
    0x00,0xF0,0x00,0x00,0x0D,0xC0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // a
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0xDF,0xFD,0xF0,0x00,0x00,0x00,
    0xEF,0x00,0xDD,0xDD,0xF0,0x00,
    0xEF,0x00,0xB0,0x00,0xCC,0x00,
    0xEF,0x00,0xD0,0x00,0x00,0xE0,
    0xFF,0x00,0xB0,0x00,0x00,0xBF,
    0xED,0x00,0xD0,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // b
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xDD,0x00,0x00,0x00,
    0x00,0x0D,0x00,0xF0,0x00,0x00,
    0x00,0x0F,0x0D,0xDD,0xDD,0xD0,
    0x00,0x0E,0x00,0x00,0x00,0x0D,
    0x00,0x0D,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // c
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xDF,0x00,0x00,0x00,0x00,
    0x00,0x00,0xDB,0xDC,0xCD,0xBE,
    0x00,0x00,0x0B,0xFD,0x00,0x00,
    0x00,0x00,0x00,0x0F,0x00,0x00,
    0x00,0x00,0x00,0x00,0xE0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // d
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xFF,0xCF,0xD0,0x00,
    0x00,0x00,0xE0,0x00,0x0D,0xD0,
    0x00,0xEB,0xF0,0x00,0x00,0x0D,
    0x00,0x00,0xD0,0x00,0x00,0x00,
    0x00,0x00,0xDD,0xED,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // e
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xE0,0x00,0x0D,0x00,
    0x00,0x00,0xD0,0x00,0x0C,0x00,
    0x00,0x00,0xFE,0xFF,0xDD,0x00,
    0x00,0x00,0xD0,0x00,0x0E,0x00,
    0x00,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // f
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xF0,0x00,0x00,0x00,
    0x00,0x00,0xD0,0x00,0x00,0x00,
    0x00,0xCC,0xDB,0xDB,0xBF,0xDF,
    0x00,0x00,0xB0,0xFE,0xB0,0x0D,
    0x00,0x00,0xB0,0x00,0xED,0x00,
    0x00,0x00,0xD0,0x00,0x00,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // g
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xD0,0x00,0x00,0x00,
    0x00,0x00,0xC0,0xFD,0x00,0x00,
    0x00,0x00,0xD0,0x00,0xFE,0xEF,
    0x00,0x0D,0xDB,0xD0,0x00,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,
    0x00,0x00,0x00,0xE0,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // h
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x0B,0x00,
    0x00,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0xFF,0xBD,0xDB,0x00,
    0x00,0x00,0xD0,0x00,0x0C,0x00,
    0x00,0x00,0xD0,0x00,0x0D,0x00,
    0x00,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // i
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xDB,0xDB,0xDF,0xFE,
    0x00,0x0D,0x00,0xD0,0x00,0xE0,
    0x00,0x0B,0x00,0xC0,0x00,0xE0,
    0x00,0x0D,0x00,0xF0,0x00,0xE0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // j
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xCB,0xDF,0x00,0x00,
    0x00,0x00,0x00,0x00,0xDD,0x00,
    0x00,0x0D,0xCD,0x00,0x00,0xBD,
    0x00,0x00,0x00,0xD0,0x00,0x0D,
    0x00,0x00,0xF0,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // k
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xDF,0xF0,0x00,0x00,
    0x00,0x00,0x00,0xFD,0x00,0x00,
    0x00,0x00,0x00,0x00,0xD0,0x00,
    0x00,0x0C,0x00,0x00,0x0B,0x00,
    0x00,0xFF,0x00,0x00,0x0B,0xF0,
    0x00,0xC0,0x00,0x00,0x00,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // l
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xD0,0x00,0x00,0x00,0x00,
    0x0D,0xCB,0x00,0x00,0x00,0x00,
    0x0D,0x00,0xCD,0x00,0x00,0x00,
    0x0D,0x0D,0xCE,0xEC,0x00,0x00,
    0x0D,0x00,0x00,0x00,0xDD,0xD0,
    0x0C,0x00,0x00,0x00,0x00,0x0D,
    0x0C,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // m
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x0C,0x00,0x00,0x00,0x00,0x00,
    0x0F,0xD0,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xCD,0xEE,0xEF,0xFF,
    0x00,0x00,0x0D,0xD0,0x00,0x00,
    0x00,0x00,0x00,0xCF,0x00,0x00,
    0x00,0x00,0x00,0x0D,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // n
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFF,0xDF,0xF0,0x00,0x00,
    0x00,0xD0,0x00,0xBD,0xEF,0x00,
    0x00,0xF0,0x00,0x00,0x0D,0xF0,
    0xDE,0xD0,0x00,0x00,0x00,0xCF,
    0x00,0xD0,0x00,0x00,0x00,0x00,
    0x00,0xED,0xEF,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // o
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xD0,0x00,0x00,0x0D,0x00,
    0x00,0xC0,0x00,0x00,0x0D,0x00,
    0x00,0xFD,0xCB,0xDD,0xDD,0x00,
    0x00,0xB0,0x00,0x00,0x0D,0x00,
    0x00,0xF0,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // p
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0F,0x00,0x00,0x00,0x00,
    0x00,0x0D,0x00,0x00,0x00,0x00,
    0xDF,0xDD,0xDE,0xDE,0xBE,0xD0,
    0x00,0x0D,0xBD,0xF0,0x00,0x0C,
    0x00,0x0F,0x00,0xDD,0x00,0x0B,
    0x00,0x0D,0x00,0x00,0xFD,0x00,
    0x00,0x0D,0x00,0x00,0x0E,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // q
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xED,0xDF,0xDF,0x00,
    0x00,0x0B,0x00,0x00,0x00,0xD0,
    0x00,0x0C,0x00,0x00,0x00,0xD0,
    0xFB,0xDD,0xFF,0xEC,0xD0,0x00,
    0x00,0x0F,0x00,0x00,0x0F,0xC0,
    0x00,0x0C,0x00,0x00,0x00,0x0F,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // r
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x0D,0xB0,0x00,0x00,
    0x0F,0xC0,0x0E,0xE0,0x00,0x00,
    0x00,0xF0,0x00,0xD0,0x00,0xCC,
    0x0E,0xFD,0xFD,0xCE,0xBF,0x00,
    0x00,0xF0,0x00,0xD0,0x00,0x00,
    0x00,0xBF,0x00,0xDD,0x00,0x00,
    0x00,0x00,0x00,0xFD,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // s
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFF,0xD0,0x00,0x00,0x00,
    0x0D,0xD0,0x0B,0xFE,0x00,0x00,
    0x0E,0xF0,0x00,0x00,0xDD,0x00,
    0xCD,0xF0,0x00,0x00,0x00,0xF0,
    0x00,0x0C,0xD0,0x00,0x00,0x0C,
    0x00,0x00,0x0F,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // t
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0C,0x00,0x00,0x00,0x00,
    0x00,0x0D,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xEB,0xCF,0x00,0x00,
    0x00,0x0F,0x00,0x00,0xEC,0xD0,
    0xBC,0xFD,0x00,0x00,0x00,0xEF,
    0x00,0xFC,0xBB,0x00,0x00,0x00,
    0x00,0x00,0x00,0xD0,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // u
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFD,0xDF,0xCC,0xCF,0xF0,
    0x00,0xE0,0x00,0x00,0x0E,0x00,
    0x00,0xB0,0x00,0x00,0x0D,0x00,
    0x00,0xC0,0x00,0x00,0x0D,0x00,
    0x00,0xD0,0x00,0x00,0x0E,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // v
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0x00,0x00,0x00,0x00,
    0x00,0x0D,0x00,0x00,0x00,0x00,
    0xBE,0xED,0xDF,0xCE,0xBD,0x00,
    0x00,0x0D,0x00,0x00,0x0E,0xE0,
    0xFF,0xDD,0xDF,0xD0,0x00,0x0C,
    0x00,0x0F,0x00,0x00,0x00,0x00,
    0x00,0x0C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // w
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xD0,0x00,0x00,0x00,
    0x00,0x00,0xDD,0xD0,0x00,0x00,
    0x00,0x00,0x00,0xDB,0x00,0x00,
    0x00,0x00,0x00,0x00,0xD0,0x00,
    0x0C,0x00,0x00,0x00,0x0F,0x00,
    0xDE,0x00,0xED,0x00,0x00,0xC0,
    0x00,0x00,0xE0,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // x
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xD0,0x00,0x00,0xFD,0x00,
    0x0C,0xDF,0xE0,0xFD,0x00,0x00,
    0x0D,0x00,0x0D,0xD0,0x00,0x00,
    0x0F,0xC0,0x00,0x0D,0xF0,0x00,
    0x0D,0xB0,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x00,0x00,0x00,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // y
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0F,0xFF,0xD0,0x00,0xD0,
    0x00,0x0F,0x00,0xCB,0x00,0xF0,
    0x00,0x0F,0xD0,0x00,0x00,0xD0,
    0xFF,0xDD,0xFF,0xCC,0xDD,0xF0,
    0x00,0x00,0xD0,0x00,0x00,0x00,
    0x00,0x00,0xDF,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // z
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x0C,0xDD,0x00,0x00,0x00,0x00,
    0x00,0x00,0xEF,0xDD,0x00,0x00,
    0x00,0x00,0x00,0x00,0xDD,0x00,
    0x00,0x00,0x00,0x00,0x0B,0xF0,
    0x00,0x0F,0xB0,0x00,0x00,0x0E,
    0x00,0xC0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 0
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xDD,0xDE,0xED,0xCD,0x00,
    0x0E,0xDD,0xB0,0x00,0x00,0xC0,
    0x0C,0x0B,0xDD,0xD0,0x00,0xE0,
    0x0D,0x00,0x00,0xEC,0xE0,0xD0,
    0x0F,0xD0,0x00,0x0E,0xDB,0xF0,
    0x00,0x0C,0xDD,0xBB,0xD0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 1
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xFF,0xED,0xFD,0xED,0xF0,
    0x00,0xDF,0xCB,0xCF,0xCE,0xC0,
    0x00,0x0E,0x00,0x00,0x00,0x00,
    0x00,0x0F,0xC0,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 2
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xD0,0x00,0x00,0xBB,0xD0,
    0x0D,0x00,0x00,0x0B,0xBF,0xD0,
    0x0E,0x00,0x00,0xBC,0x00,0xD0,
    0x0D,0x00,0x0C,0xD0,0x00,0xF0,
    0x0F,0xD0,0xFD,0x00,0x00,0xD0,
    0x00,0xDE,0xC0,0x00,0x00,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 3
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0F,0xDE,0x00,0x0B,0xC0,
    0x00,0xFD,0x0E,0xB0,0xFD,0xD0,
    0x00,0xD0,0x00,0xDD,0xC0,0xF0,
    0x00,0xF0,0x00,0xEE,0x00,0xD0,
    0x00,0xD0,0x00,0x00,0x00,0xF0,
    0x00,0xD0,0x00,0x00,0x00,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 4
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xBD,0xDF,0xB0,
    0x00,0xB0,0x00,0x00,0xD0,0x00,
    0x00,0x0D,0xF0,0x00,0xB0,0x00,
    0x00,0x00,0x0B,0xD0,0xD0,0x00,
    0x00,0x00,0x00,0x0D,0xD0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 5
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xED,0xBD,0x00,0x00,0xD0,
    0x00,0xC0,0x0E,0x00,0x00,0xB0,
    0x00,0xB0,0x0F,0x00,0x00,0xF0,
    0x00,0xE0,0x0D,0xD0,0xFF,0x00,
    0x00,0xF0,0x00,0xDB,0xF0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 6
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xFD,0xCE,0x00,
    0x00,0xD0,0x0D,0x00,0x00,0xD0,
    0x00,0xDF,0x0E,0x00,0x00,0xE0,
    0x00,0x0D,0xFF,0x00,0x00,0xF0,
    0x00,0x00,0x0C,0xD0,0x0D,0xF0,
    0x00,0x00,0x00,0xCF,0xD0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 7
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xBF,0x00,0x00,0x00,0x00,
    0x00,0xF0,0xE0,0x00,0x00,0x00,
    0x00,0xD0,0x0B,0xD0,0x00,0x00,
    0x00,0xD0,0x00,0xDD,0xFF,0xD0,
    0x00,0xD0,0x00,0x00,0x0D,0xF0,
    0x00,0xB0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 8
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xF0,0x0D,0xFB,0x00,
    0x00,0xF0,0x0F,0xF0,0x00,0xF0,
    0x00,0xF0,0x0F,0xE0,0x00,0xE0,
    0x00,0xB0,0x0D,0xC0,0x00,0xB0,
    0x00,0xBD,0xCE,0xCD,0x0B,0xD0,
    0x00,0x00,0x00,0x0D,0xDC,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // 9
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xCE,0x00,0x00,0x00,
    0x00,0xD0,0x00,0xF0,0x00,0xD0,
    0x00,0xD0,0x00,0xE0,0x0D,0xD0,
    0x00,0xF0,0x00,0xDF,0xFE,0x00,
    0x00,0xEC,0x0D,0xFD,0x00,0x00,
    0x00,0x0F,0xDD,0xB0,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // .
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x0F,0xD0,0x00,
    0x00,0x00,0x00,0xFD,0x00,0x00,
    0x00,0x00,0xDD,0x00,0x00,0x00,
    0x00,0xCE,0x00,0x00,0x00,0x00,
    0x00,0xFD,0x00,0x00,0x00,0x00,
    0x00,0x00,0xDD,0x00,0x00,0x00,
    0x00,0x00,0x00,0xE0,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // :
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x0F,0xDD,0xB0,0x00,0x00,0x00,
    0x0B,0x00,0xCC,0xD0,0x0D,0xB0,
    0x0F,0xD0,0x00,0xDF,0xD0,0x00,
    0x0D,0xD0,0x00,0xBD,0x00,0x00,
    0x0D,0xD0,0x00,0x00,0x00,0x00,
    0x00,0xF0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // ,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xDD,0x00,0x00,0x00,0xF0,
    0x00,0x0F,0x00,0x00,0x00,0xE0,
    0x00,0x0E,0xF0,0x00,0x00,0xB0,
    0x00,0x00,0xD0,0x00,0x00,0xE0,
    0xFE,0xDB,0xFB,0xBE,0xDD,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // ;
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x0F,0x00,0x0F,0x00,0x0D,0xD0,
    0x0B,0x00,0x0B,0x00,0x0D,0x00,
    0xFE,0x00,0xEB,0x00,0xFD,0x00,
    0xBC,0x00,0xB0,0x00,0xD0,0x00,
    0x00,0x00,0x00,0x0F,0xF0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // '
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xD0,0x00,
    0x00,0xB0,0x00,0x00,0xD0,0x00,
    0x00,0xD0,0x00,0x00,0xF0,0x00,
    0x00,0xD0,0x00,0x00,0xD0,0x00,
    0x00,0xB0,0x00,0x00,0xD0,0x00,
    0x00,0x00,0x00,0x00,0xE0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // "
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x0D,0x00,0x00,0x00,
    0xDD,0x00,0x0D,0x00,0x00,0x00,
    0x0D,0x00,0x0D,0x00,0x00,0x00,
    0x0F,0xCF,0xDD,0xDE,0xDB,0x00,
    0x0C,0xD0,0x0D,0x00,0x0D,0xDD,
    0x0F,0xD0,0x0C,0x00,0x00,0x00,
    0x00,0x00,0x0F,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // (
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xD0,0x00,0x00,0xDD,0x00,
    0x0D,0xFD,0xDD,0x0F,0xF0,0x00,
    0x0D,0x00,0x0F,0xFE,0x00,0x00,
    0x0D,0x00,0xFF,0x0D,0xD0,0x00,
    0x0D,0x00,0x00,0x00,0x0E,0x00,
    0x00,0x00,0x00,0x00,0x00,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // !
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xD0,0x00,0x00,0x00,0x00,
    0x0F,0xDD,0xDB,0xDD,0x00,0x00,
    0x0E,0xD0,0x0D,0xCF,0xC0,0x00,
    0xDE,0xE0,0x0F,0x00,0x0D,0xD0,
    0x00,0xCD,0xF0,0x00,0x00,0xFE,
    0x00,0x00,0x0D,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // ?
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xDC,0xF0,0x00,0x00,0x00,
    0x00,0xF0,0x0D,0xE0,0x00,0x00,
    0x00,0x0B,0x00,0x00,0x00,0x0F,
    0x00,0x0C,0x0F,0xDD,0xCD,0xCD,
    0xBF,0xDC,0xF0,0x00,0x00,0x00,
    0x00,0x00,0xD0,0x00,0x00,0x00,
    0x00,0x00,0xBD,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // )
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xF0,0x00,
    0x00,0xE0,0x00,0xDB,0x00,0x00,
    0x00,0xDF,0x00,0xF0,0x00,0x00,
    0xDD,0xC0,0xDC,0xED,0xFC,0xFB,
    0x00,0xC0,0x00,0xDF,0x00,0x00,
    0x00,0xF0,0x00,0x0D,0x00,0x00,
    0x00,0x00,0x00,0x00,0xF0,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // +
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x0C,0xEF,0x00,
    0x00,0x0C,0xDC,0xF0,0x00,0x00,
    0x00,0xFD,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xFB,0x00,0x00,0x00,
    0x00,0x00,0x00,0xDD,0xDC,0x00,
    0x00,0x00,0x00,0x00,0x0E,0xF0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // -
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x0D,0xFF,0xF0,0x00,0x00,0x00,
    0x0E,0x00,0xFB,0xDB,0x00,0x00,
    0x0D,0x00,0x00,0x0F,0xD0,0x00,
    0x0D,0x00,0x00,0x00,0x0D,0x00,
    0x0B,0x00,0x00,0x00,0x0F,0xC0,
    0x0E,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // *
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0xED,0xFF,0x00,0x00,0x00,0x00,
    0x00,0x0D,0xDE,0xF0,0x00,0x00,
    0x00,0x00,0x00,0xDF,0xD0,0x00,
    0x00,0x00,0x00,0x00,0xFD,0x00,
    0x00,0x00,0x00,0x00,0x0D,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // /
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0D,0x00,0x00,0xBF,0x00,
    0x00,0x0F,0x0F,0xDC,0x00,0x00,
    0x00,0x0D,0x00,0xD0,0x00,0x00,
    0xCB,0xFB,0xFE,0xFE,0xCB,0xBB,
    0x00,0x0D,0x00,0x00,0x00,0x00,
    0x00,0x0F,0x0D,0xDD,0xC0,0x00,
    0x00,0x0D,0x00,0x00,0x0E,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    // =
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0xDD,0xF0,0x00,0xDE,0x00,0x00,
    0x00,0x0F,0xCE,0xD0,0x00,0x00,
    0x00,0x00,0xD0,0xDE,0xF0,0x00,
    0x00,0x00,0x00,0x00,0xDD,0x00,
    0x00,0x00,0x00,0x00,0x00,0xC0,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00
};

const uint8_t Matrix_GlyphDataLength = 77;
const Glyph Matrix_GlyphData[] PROGMEM = {
    {0, 12, 12, 14, 0, -12}, 
    {72, 12, 12, 14, 0, -12}, 
    {144, 12, 12, 14, 0, -12}, 
    {216, 12, 12, 14, 0, -12}, 
    {288, 12, 12, 14, 0, -12}, 
    {360, 12, 12, 14, 0, -12}, 
    {432, 12, 12, 14, 0, -12}, 
    {504, 12, 12, 14, 0, -12}, 
    {576, 12, 12, 14, 0, -12}, 
    {648, 12, 12, 14, 0, -12}, 
    {720, 12, 12, 14, 0, -12}, 
    {792, 12, 12, 14, 0, -12}, 
    {864, 12, 12, 14, 0, -12}, 
    {936, 12, 12, 14, 0, -12}, 
    {1008, 12, 12, 14, 0, -12}, 
    {1080, 12, 12, 14, 0, -12}, 
    {1152, 12, 12, 14, 0, -12}, 
    {1224, 12, 12, 14, 0, -12}, 
    {1296, 12, 12, 14, 0, -12}, 
    {1368, 12, 12, 14, 0, -12}, 
    {1440, 12, 12, 14, 0, -12}, 
    {1512, 12, 12, 14, 0, -12}, 
    {1584, 12, 12, 14, 0, -12}, 
    {1656, 12, 12, 14, 0, -12}, 
    {1728, 12, 12, 14, 0, -12}, 
    {1800, 12, 12, 14, 0, -12}, 
    {1872, 12, 12, 14, 0, -12}, 
    {1944, 12, 12, 14, 0, -12}, 
    {2016, 12, 12, 14, 0, -12}, 
    {2088, 12, 12, 14, 0, -12}, 
    {2160, 12, 12, 14, 0, -12}, 
    {2232, 12, 12, 14, 0, -12}, 
    {2304, 12, 12, 14, 0, -12}, 
    {2376, 12, 12, 14, 0, -12}, 
    {2448, 12, 12, 14, 0, -12}, 
    {2520, 12, 12, 14, 0, -12}, 
    {2592, 12, 12, 14, 0, -12}, 
    {2664, 12, 12, 14, 0, -12}, 
    {2736, 12, 12, 14, 0, -12}, 
    {2808, 12, 12, 14, 0, -12}, 
    {2880, 12, 12, 14, 0, -12}, 
    {2952, 12, 12, 14, 0, -12}, 
    {3024, 12, 12, 14, 0, -12}, 
    {3096, 12, 12, 14, 0, -12}, 
    {3168, 12, 12, 14, 0, -12}, 
    {3240, 12, 12, 14, 0, -12}, 
    {3312, 12, 12, 14, 0, -12}, 
    {3384, 12, 12, 14, 0, -12}, 
    {3456, 12, 12, 14, 0, -12}, 
    {3528, 12, 12, 14, 0, -12}, 
    {3600, 12, 12, 14, 0, -12}, 
    {3672, 12, 12, 14, 0, -12}, 
    {3744, 12, 12, 14, 0, -12}, 
    {3816, 12, 12, 14, 0, -12}, 
    {3888, 12, 12, 14, 0, -12}, 
    {3960, 12, 12, 14, 0, -12}, 
    {4032, 12, 12, 14, 0, -12}, 
    {4104, 12, 12, 14, 0, -12}, 
    {4176, 12, 12, 14, 0, -12}, 
    {4248, 12, 12, 14, 0, -12}, 
    {4320, 12, 12, 14, 0, -12}, 
    {4392, 12, 12, 14, 0, -12}, 
    {4464, 12, 12, 14, 0, -12}, 
    {4536, 12, 12, 14, 0, -12}, 
    {4608, 12, 12, 14, 0, -12}, 
    {4680, 12, 12, 14, 0, -12}, 
    {4752, 12, 12, 14, 0, -12}, 
    {4824, 12, 12, 14, 0, -12}, 
    {4896, 12, 12, 14, 0, -12}, 
    {4968, 12, 12, 14, 0, -12}, 
    {5040, 12, 12, 14, 0, -12}, 
    {5112, 12, 12, 14, 0, -12}, 
    {5184, 12, 12, 14, 0, -12}, 
    {5256, 12, 12, 14, 0, -12}, 
    {5328, 12, 12, 14, 0, -12}, 
    {5400, 12, 12, 14, 0, -12}, 
    {5472, 12, 12, 14, 0, -12}
};

const BitmapFont Matrix PROGMEM = {
	 Matrix_Palette,
	 16,

	 Matrix_BitmapData,    
	 12,		

	 Matrix_GlyphData,    
	 77 
};



