#include <Wire.h>
#define SDA 2
#define SCL 3

void setup() {
  Wire.begin(0x101);
}

void loop() {
  Wire.beginTransmission(0x100);
  Wire.print("TESTE");
  Wire.endTransmission();
  delay(2000);
}
