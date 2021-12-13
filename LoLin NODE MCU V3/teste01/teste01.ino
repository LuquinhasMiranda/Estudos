void setup() {
  pinMode(D2, OUTPUT);
}

void loop() {
  delay(500);
  digitalWrite(D2, HIGH);
  delay(500);
  digitalWrite(D2, LOW);
}
