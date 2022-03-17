#include <Wire.h>
#define SDA 2
#define SCL 3

void setup() {
  Serial.begin(9600);
  Wire.begin(0x100);
  Wire.onReceive(&Receber);
  pinMode(30, OUTPUT);
}

void loop() {

}

void Receber(int qnt) {
  int data;
  while(Wire.available()>0 ) { 
    data = int(Wire.read()); 
    Serial.print(data);
  }
}
