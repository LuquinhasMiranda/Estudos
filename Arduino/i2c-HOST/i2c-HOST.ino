#include <Wire.h>
#define SDA 2
#define SCL 3

void setup() {
  Wire.begin(0x101);
}
bool sw = false;
void loop() {
  Wire.beginTransmission(0x100);
  sw = !sw;
  if (sw) Wire.print(1);
  else Wire.print(0);
  
  Wire.endTransmission();
  delay(2000);
}
