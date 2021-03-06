#include <Wire.h>  // i2c
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     0 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

static const unsigned PROGMEM char Nike [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x77, 0x67, 0xFA, 0x00, 0x00,
0x00, 0x00, 0x0F, 0x76, 0xEF, 0xF9, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x6E, 0xFD, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x0F, 0xEE, 0xF9, 0x80, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xED, 0xF3, 0x80, 0x00, 0x00,
0x00, 0x00, 0x1F, 0xDD, 0xE3, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xDB, 0xE7, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x3F, 0xBB, 0xF7, 0x00, 0x00, 0x00, 0x00, 0x01, 0x37, 0xBB, 0x66, 0x00, 0x30, 0x00,
0x00, 0x03, 0x77, 0xB7, 0x6F, 0xC3, 0x80, 0x00, 0x00, 0x06, 0x77, 0x76, 0x7F, 0xDE, 0x00, 0x00,
0x00, 0x06, 0x67, 0x66, 0x7F, 0xF0, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x3F, 0xC0, 0x00, 0x00,
0x00, 0x0E, 0x00, 0x03, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x3F, 0xF8, 0x00, 0x00, 0x00,
0x00, 0x1F, 0xC3, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
0x00, 0x3F, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x1F, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned PROGMEM char Adidas [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFE, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x07, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0x80, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0xFF, 0xC0, 0x00, 0x00,
0x00, 0x00, 0x00, 0x70, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x03, 0xF8, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xF8, 0x7F, 0xF0, 0x00, 0x00,
0x00, 0x00, 0x0F, 0xFC, 0x7F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFC, 0x3F, 0xF8, 0x00, 0x00,
0x00, 0x00, 0x0F, 0xFE, 0x3F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xFE, 0x3F, 0xF8, 0x00, 0x00,
0x00, 0x00, 0x07, 0xFE, 0x1F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x1F, 0xFC, 0x00, 0x00,
0x00, 0x00, 0x07, 0xFF, 0x0F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x43, 0xFF, 0x8F, 0xFE, 0x00, 0x00,
0x00, 0x00, 0xE3, 0xFF, 0x8F, 0xFE, 0x00, 0x00, 0x00, 0x03, 0xE1, 0xFF, 0x87, 0xFF, 0x00, 0x00,
0x00, 0x07, 0xE1, 0xFF, 0xC7, 0xFF, 0x00, 0x00, 0x00, 0x0F, 0xF1, 0xFF, 0xC3, 0xFF, 0x00, 0x00,
0x00, 0x1F, 0xF0, 0xFF, 0xE3, 0xFF, 0x80, 0x00, 0x00, 0x3F, 0xF8, 0xFF, 0xE3, 0xFF, 0x80, 0x00,
0x00, 0x3F, 0xF8, 0xFF, 0xE1, 0xFF, 0xC0, 0x00, 0x00, 0x1F, 0xF8, 0x7F, 0xF1, 0xFF, 0xC0, 0x00,
0x00, 0x1F, 0xFC, 0x7F, 0xF1, 0xFF, 0xC0, 0x00, 0x00, 0x1F, 0xFC, 0x3F, 0xF0, 0xFF, 0xE0, 0x00,
0x00, 0x00, 0x03, 0xB0, 0x06, 0x00, 0x00, 0x40, 0x00, 0x00, 0x03, 0xB0, 0x06, 0x00, 0x00, 0x40,
0x00, 0x00, 0x03, 0xB0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x06, 0x00, 0x00, 0x00,
0x01, 0xCC, 0x3B, 0xB0, 0xE6, 0x1D, 0x87, 0x00, 0x03, 0xFC, 0x7F, 0xB1, 0xFE, 0x3F, 0xCF, 0x80,
0x07, 0xFC, 0xFF, 0xB3, 0xFE, 0x7F, 0xDF, 0xC0, 0x07, 0x3D, 0xEF, 0xB3, 0x9E, 0xF7, 0xD8, 0xC0,
0x0E, 0x1D, 0xC7, 0xB7, 0x0E, 0xE3, 0xD8, 0xC0, 0x0C, 0x1D, 0x83, 0xB7, 0x0E, 0xC1, 0xDE, 0x00,
0x0C, 0x1D, 0x83, 0xB6, 0x06, 0xC1, 0xDF, 0xC0, 0x0C, 0x0D, 0x83, 0xB6, 0x06, 0xC1, 0xCF, 0xC0,
0x0C, 0x1D, 0x83, 0xB6, 0x0E, 0xC1, 0xC7, 0xE0, 0x0E, 0x1D, 0x83, 0xB7, 0x0E, 0xC1, 0xC0, 0xE0,
0x0E, 0x3D, 0xC7, 0xB7, 0x1E, 0xE3, 0xD8, 0xE0, 0x07, 0xFC, 0xFF, 0xB3, 0xFE, 0x7F, 0xDC, 0xE0,
0x07, 0xFC, 0xFF, 0xB3, 0xFE, 0x7F, 0xDF, 0xC0, 0x03, 0xFC, 0x7F, 0xB1, 0xFE, 0x3F, 0xCF, 0xC0,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};




void setup() {
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    
    for(;;); 
   }

}

void loop() {
  display.clearDisplay();
  display.drawBitmap(0,0,Adidas,64,64,1);
  display.drawBitmap(65,0,Nike,64,64,1);
  display.display();

}
