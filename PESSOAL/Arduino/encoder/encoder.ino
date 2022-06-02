#include "Encoder.h"

void a() {
  Serial.println("A");  
}
void b() {
  Serial.println("B");  
}
void c() {
  Serial.println("C");  
}
void d() {
  Serial.println("D");  
}
void sw() {
  Serial.println("SW");  
}
Encoder _encoder(19,20,21,a,b,c,d,sw);

void setup() {
  Serial.begin(9600);
}

void loop() {
  _encoder.check();
}
