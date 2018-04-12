# Matrix44
Matrix animation for Teensy and maybe for some Arduinos.

Sample:

Programmsize is approx. 53.856 bytes and memory usage is 29952 bytes
Memory usage can be reduced with reducing the shown strips (MAX_STRIPES) and the letter buffer( MAX_LETTERS).

## Configuration

If you want to tweek the anmiation take a look at Configuration.h and change the constants there 
(some settings may crash the animation or increase the memory consumption, so be carefull).

To change the font, just copy the matrixFont.h and add your own glyph patterns.
Then include the new header and adopt the USED_FONT constant. The glyph format is a 4 bit per pixel paletted bitmap. 
You might also use my bitmap font editor and generate the header from there. (See add link)

## Hardware

I programmed this for the Teensy 3.2 and used the wiring information from:
https://www.pjrc.com/store/display_ili9341_touch.html

For using the touch screen too checkout https://github.com/PaulStoffregen/ILI9341_t3/blob/master/examples/touchpaint/touchpaint.ino
and remember to replace the "Adafruit_STMPE610" library with the "XPT2046_Touchscreen" library if the XPT2046 controller is used in your tft (and you may need to swap the x and y axis).

## Div

When you are planning to create your own animation with the Adrafuits or the PJRC ILI9341 library and you have to clip bitmaps at the screen border 
the method "Graph::DrawGlyph" helps you. The the methods "ILI9341_t3_sk::writeRect4BPP" and "LI9341_t3_sk::writeRect4BPPstartinghalfByte" add the possiblity to 
draw bitmaps with uneven widths and to draw parts of the bitmap with uneven pixel offsets.

## Thanks to 

Paul Stoffregen for building the Teensy and wiring information (see https://www.pjrc.com/teensy/ ) 
