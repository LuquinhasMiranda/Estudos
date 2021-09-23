int tempo;

void setup() {
  pinMode(30, OUTPUT);
  tempo = 1000;
}

void loop() {
  digitalWrite(30, LOW);
  delay(15);
  digitalWrite(30, HIGH);
  delay(tempo);
  tempo = tempo-50;
}
