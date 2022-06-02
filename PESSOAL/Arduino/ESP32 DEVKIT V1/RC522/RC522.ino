#include <SPI.h>
#include <MFRC522.h>

MFRC522 rfid(5, 4);

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println(F("LEITOR:"));
}

void loop() {

  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
  MFRC522::MIFARE_Key key;
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  //some variables we need
  byte block;
  byte len;
  MFRC522::StatusCode status;
  

  byte buffer1[18];

  block = 4;
  len = 18;

  //-------------------------------------------

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! rfid.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println(F("**Card Detected:**"));

  //-------------------------------------------
  status = rfid.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(rfid.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }

  status = rfid.MIFARE_Read(block, buffer1, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(rfid.GetStatusCodeName(status));
    return;
  }

  rfid.PICC_DumpDetailsToSerial(&(rfid.uid)); //dump some details about the card

  rfid.PICC_DumpToSerial(&(rfid.uid));      //uncomment this to see all blocks in hex

  delay(1000); //change value if you want to read cards faster

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
