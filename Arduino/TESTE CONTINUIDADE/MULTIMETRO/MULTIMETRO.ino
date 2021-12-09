void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,INPUT_PULLUP);
}

int cache = 0;
void loop() {
  int check = digitalRead(3);
  if (check != cache) 
  {
    if (!check) digitalWrite(13, HIGH);
    if (check) digitalWrite(13, LOW);
    cache = check;  
  }
}
