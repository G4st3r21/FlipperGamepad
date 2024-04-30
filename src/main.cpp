#include <SPI.h>
#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI(240, 280);

void testlines(uint16_t color);
void testfastlines(uint16_t color1, uint16_t color2);
void testdrawrects(uint16_t color);
void testfillrects(uint16_t color1, uint16_t color2);

void setup(void) {
  Serial.begin(9600);
  Serial.print("Hello! ST7789 Test");

  tft.init(); // Display resolution

  Serial.println("Init Success!");

  uint16_t time = millis();
  tft.fillScreen(TFT_BLACK);
  time = millis() - time;

  Serial.println(time, DEC);
  delay(500);

  // Check if the display is working
  tft.invertDisplay(true);
  delay(500);
  tft.invertDisplay(false);
  delay(500);

  // Start a series of graphic tests
  testlines(TFT_CYAN);
  delay(500);
  testfastlines(TFT_RED, TFT_BLUE);
  delay(500);
  testdrawrects(TFT_GREEN);
  delay(500);
  testfillrects(TFT_YELLOW, TFT_MAGENTA);

  // More examples...
}

void loop() {
  // Nothing to do here.
}

// Test functions

void testlines(uint16_t color) {
   tft.fillScreen(TFT_BLACK);
   for (int16_t x=0; x < tft.width(); x+=6) {
      tft.drawLine(0, 0, x, tft.height()-1, color);
   }
   //...
}

void testfastlines(uint16_t color1, uint16_t color2) {
   tft.fillScreen(TFT_BLACK);
   for (int16_t y=0; y < tft.height(); y+=5) {
      tft.drawFastHLine(0, y, tft.width(), color1);
   }
   //...
}

void testdrawrects(uint16_t color) {
   tft.fillScreen(TFT_BLACK);
   for (uint16_t x=0; x < tft.width(); x+=6) {
      tft.drawRect(tft.width()/2 - x/2, tft.height()/2 - x/2 , x, x, color);
   }
}

void testfillrects(uint16_t color1, uint16_t color2) {
   tft.fillScreen(TFT_BLACK);
   uint8_t i;
   for (i=0; i<tft.height(); i+= 3) {
      uint16_t color = i/(tft.height()/6) + 1;
      tft.fillRect(tft.width()/2 - i/2, tft.height()/2 - i/2 , i, i, color);
   }
}

// Add more test functions if desired...