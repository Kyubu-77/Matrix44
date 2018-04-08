#include <font_Arial.h>
#include <font_ArialBold.h>
#include <ILI9341_t3.h>

#include "Arduino.h"

//Teensy
#include "SPI.h"
#include "ILI9341_t3_sk.h"

//Own 
#include "Printer.h"
#include "Utils.h"

#include "Configuration.h"
#include "Graph.h"

// For the Adafruit shield, these are the default.
#define TFT_DC  9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
ILI9341_t3_sk tft = ILI9341_t3_sk(TFT_CS, TFT_DC);
Graph graph = Graph(tft, MAX_STRIPES);

unsigned long lastTick = 0;

unsigned long delayyy = 50;

void setup() {
	// TFT
	tft.begin();
	tft.fillScreen(ILI9341_BLACK);
	tft.setTextColor(ILI9341_YELLOW);
	tft.setTextSize(2);
	tft.println("Waiting for Arduino Serial Monitor...");

	// Serial
	Serial.begin(9600);
	//while (!Serial); // wait for Arduino Serial Monitor
	tft.println("Connected");
	Serialprint("Starting");

	// Info
	uint8_t x = tft.readcommand8(ILI9341_RDMODE);
	Serialprint("Display Power Mode: %02x", x);
	x = tft.readcommand8(ILI9341_RDMADCTL);
	Serialprint("MADCTL Mode: %02x", x);
	x = tft.readcommand8(ILI9341_RDPIXFMT);
	Serialprint("Pixel Format: %02x", x);
	x = tft.readcommand8(ILI9341_RDIMGFMT);
	Serialprint("Image Format: %02x", x);
	x = tft.readcommand8(ILI9341_RDSELFDIAG);
	Serialprint("Image RDSELFDIAG: %02x", x);
	Serialprint("tft.width: %d\n", tft.width());
	Serialprint("tft.height: %d\n", tft.height());

	// Graphic
	tft.fillScreen(ILI9341_BLACK);

	graph.SetFont(USED_FONT);
	graph.SetPalette(PALETTE, PALETTE_SIZE, LETTER_ALPHA_BITS);

	lastTick = millis();
}


void loop() {
	unsigned long now = millis();
	uint16_t diff = now - lastTick;
	
	if (diff > 0) {
		lastTick = now;
		graph.Tick(diff);
		graph.Draw();
		delay(10);
	}

}
