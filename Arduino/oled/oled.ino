#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 32, &Wire, 4);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setRotation(3);

  // Clear the buffer
  display.clearDisplay();
  display.display();
}

void loop() {
  delay(2000);
  display.clearDisplay();
  oledHexagono(0, 2);
  display.display();
  delay(2000);
  display.clearDisplay();
  oledHexagono(0, 1);
  display.display();
}

void oledHexagono(int offy, int img_version) {
  if (img_version==1) {
    display.drawFastHLine(8,0+offy,16,WHITE);
    display.drawPixel(7,1+offy,WHITE);
    display.drawPixel(7,2+offy,WHITE);
    display.drawPixel(6,3+offy,WHITE);
    display.drawPixel(6,4+offy,WHITE);
    display.drawPixel(5,5+offy,WHITE);
    display.drawPixel(5,6+offy,WHITE);
    display.drawPixel(4,7+offy,WHITE);
    display.drawPixel(3,8+offy,WHITE);
    display.drawPixel(3,9+offy,WHITE);
    display.drawPixel(2,10+offy,WHITE);
    display.drawPixel(2,11+offy,WHITE);
    display.drawPixel(1,12+offy,WHITE);
    display.drawPixel(0,13+offy,WHITE);
    display.drawPixel(0,14+offy,WHITE);
    display.drawPixel(1,15+offy,WHITE);
    display.drawPixel(2,16+offy,WHITE);
    display.drawPixel(2,17+offy,WHITE);
    display.drawPixel(3,18+offy,WHITE);
    display.drawPixel(3,19+offy,WHITE);
    display.drawPixel(4,20+offy,WHITE);
    display.drawPixel(5,21+offy,WHITE);
    display.drawPixel(5,22+offy,WHITE);
    display.drawPixel(6,23+offy,WHITE);
    display.drawPixel(6,24+offy,WHITE);
    display.drawPixel(7,25+offy,WHITE);
    display.drawPixel(7,26+offy,WHITE);
    display.drawPixel(31-7,1+offy,WHITE);
    display.drawPixel(31-7,2+offy,WHITE);
    display.drawPixel(31-6,3+offy,WHITE);
    display.drawPixel(31-6,4+offy,WHITE);
    display.drawPixel(31-5,5+offy,WHITE);
    display.drawPixel(31-5,6+offy,WHITE);
    display.drawPixel(31-4,7+offy,WHITE);
    display.drawPixel(31-3,8+offy,WHITE);
    display.drawPixel(31-3,9+offy,WHITE);
    display.drawPixel(31-2,10+offy,WHITE);
    display.drawPixel(31-2,11+offy,WHITE);
    display.drawPixel(31-1,12+offy,WHITE);
    display.drawPixel(31-0,13+offy,WHITE);
    display.drawPixel(31-0,14+offy,WHITE);
    display.drawPixel(31-1,15+offy,WHITE);
    display.drawPixel(31-2,16+offy,WHITE);
    display.drawPixel(31-2,17+offy,WHITE);
    display.drawPixel(31-3,18+offy,WHITE);
    display.drawPixel(31-3,19+offy,WHITE);
    display.drawPixel(31-4,20+offy,WHITE);
    display.drawPixel(31-5,21+offy,WHITE);
    display.drawPixel(31-5,22+offy,WHITE);
    display.drawPixel(31-6,23+offy,WHITE);
    display.drawPixel(31-6,24+offy,WHITE);
    display.drawPixel(31-7,25+offy,WHITE);
    display.drawPixel(31-7,26+offy,WHITE);
    display.drawFastHLine(8,27+offy,16,WHITE);
  }
  else if (img_version==2) {
    display.drawFastHLine(8,0+offy,16,WHITE);
    display.drawFastHLine(7,1+offy,18,WHITE);
    display.drawFastHLine(7,2+offy,18,WHITE);
    display.drawFastHLine(6,3+offy,20,WHITE);
    display.drawFastHLine(6,4+offy,20,WHITE);
    display.drawFastHLine(5,5+offy,22,WHITE);
    display.drawFastHLine(5,6+offy,22,WHITE);
    display.drawFastHLine(4,7+offy,24,WHITE);
    display.drawFastHLine(3,8+offy,26,WHITE);
    display.drawFastHLine(3,9+offy,26,WHITE);
    display.drawFastHLine(2,10+offy,28,WHITE);
    display.drawFastHLine(2,11+offy,28,WHITE);
    display.drawFastHLine(1,12+offy,30,WHITE);
    display.drawFastHLine(0,13+offy,32,WHITE);
    display.drawFastHLine(0,14+offy,32,WHITE);
    display.drawFastHLine(1,15+offy,30,WHITE);
    display.drawFastHLine(2,16+offy,28,WHITE);
    display.drawFastHLine(2,17+offy,28,WHITE);
    display.drawFastHLine(3,18+offy,26,WHITE);
    display.drawFastHLine(3,19+offy,26,WHITE);
    display.drawFastHLine(4,20+offy,24,WHITE);
    display.drawFastHLine(5,21+offy,22,WHITE);
    display.drawFastHLine(5,22+offy,22,WHITE);
    display.drawFastHLine(6,23+offy,20,WHITE);
    display.drawFastHLine(6,24+offy,20,WHITE);
    display.drawFastHLine(7,25+offy,18,WHITE);
    display.drawFastHLine(7,26+offy,18,WHITE);
    display.drawFastHLine(8,27+offy,16,WHITE);
  }
}
