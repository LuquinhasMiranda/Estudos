int tempo;

void setup() {
  pinMode(30, OUTPUT);
  pinMode(0, OUTPUT);
  digitalWrite(0, LOW);
  pinMode(1, INPUT_PULLUP);
  delay(100);
  if (digitalRead(1)) tempo = 200;
  else tempo = 1000;
}

void loop() {
  delay(tempo);
  digitalWrite(30, HIGH);
  delay(tempo);
  digitalWrite(30, LOW);
}
