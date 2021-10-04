#include "Arduino.h"
#include "Encoder.h"

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

Encoder::Encoder(int pinA, int pinB, int pinSW, void (*funcA)(), void (*funcB)(), void (*funcC)(), void (*funcD)(), void (*funcSW)()) { // CONSTRUTOR DA LIB
  _pinA = pinA;
  _pinB = pinB;
  _pinSW = pinSW;
  _funcA = funcA;
  _funcB = funcB;
  used_modifier = 0;
  _funcC = funcC;
  _funcD = funcD;
  _funcSW = funcSW;
  pinMode(_pinA, INPUT_PULLUP);
  pinMode(_pinB, INPUT_PULLUP);
  pinMode(_pinSW, INPUT_PULLUP);
  encoder_last = get_encoder_position();
  encoder_reset = 0;
}

void Encoder::check() { // COLOCAR NO LOOP PARA ATUALIZAR CONSTANTEMENTE

  //PARTE DO ENCODER
  encoder_position = get_encoder_position();
  if (encoder_position != encoder_last) {
    if (encoder_position == 1) encoder_reset++;
    else if (encoder_position == 3) {
      if (encoder_reset > 0) {
        if      (encoder_last == 2 && switch_position)  _funcA();
        else if (encoder_last == 4 && switch_position)  _funcB();
        else if (encoder_last == 2 && !switch_position){_funcC();used_modifier++;}
        else if (encoder_last == 4 && !switch_position){_funcD();used_modifier++;}
        encoder_reset = 0;
      }
    }
  }
  encoder_last = encoder_position;

  //PARTE DO SWITCH
  switch_position = digitalRead(_pinSW);
  if (switch_position != switch_last) {
    if (switch_position) {
      if (used_modifier==0) _funcSW();
      used_modifier = 0;
    }
    switch_last = switch_position;
  }
}

int Encoder::get_encoder_position() {
  int a;
  if (digitalRead(_pinA)) a = 1;
  else a = 0;

  int b;
  if (digitalRead(_pinB)) b = 1;
  else b = 0;

  if      (a == 0 && b == 0) return 1;
  else if (a == 1 && b == 0) return 2;
  else if (a == 1 && b == 1) return 3;
  else if (a == 0 && b == 1) return 4;
}
