#ifndef Encoder_h
#define Encoder_h
#include "Arduino.h"

/* EXEMPLO DE SKETCH
#include "Encoder.h"
//FUNCOES DO ENCODER
void direita() {
  Serial.println("direita");  
}
void esquerda() {
  Serial.println("esquerda");  
}
void swclick() {
  Serial.println("click");  
}

Encoder enc(4, 5, 6, &direita, &esquerda, &swclick);

void setup() {
  Serial.begin(9600);
}

void loop() {
  enc.check();
}
*/

class Encoder
{
  public:
    Encoder(int pinA, int pinB, int pinSW, void (*funcA)(), void (*funcB)(), void (*funcC)(), void (*funcD)(), void (*funcSW)());
    void check();
  private:
    int get_encoder_position();
  
    // ENCODER
    int encoder_position, encoder_last, encoder_reset;
    int _pinA, _pinB;
    void (*_funcA)(),(*_funcB)(),(*_funcC)(),(*_funcD)();
    int count;
    // SWITCH DO ENCODER
    int switch_position, switch_last;
    int _pinSW;
    void (*_funcSW)();
    int used_modifier;
};

#endif
