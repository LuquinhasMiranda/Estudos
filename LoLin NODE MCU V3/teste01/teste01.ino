void setup() {
  pinMode(D4, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(D4, HIGH);
  delay(500);
  digitalWrite(D4, LOW);
}
