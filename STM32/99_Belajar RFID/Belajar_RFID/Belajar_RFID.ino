// Penggunaan RFID Pada STM32
// RFID menggunakan komunikasi SPI
// Jadi perlu PIN SDA SCK MISO MOSI dan RST

// Inisialize
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN PB7 // Karena PB7 dan PB11 merupakan PIN SDA di STM32
#define RST_PIN PB0 // Pin Reset bebas menggunakan PIN Mana Saja
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin (115200); // Baudrate yang digunakan
  SPI.begin(); // Initiate SPI
  mfrc522.PCD_Init(); // Initiate MFRC522

}

void loop() {
  // Program yang diulang
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  // Pilihan Satu Kartu
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}

  // Show UID di serial monitor
  Serial.print ("UID Tag: ");
  String content=  "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ""));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  Serial.println();
  Serial.print("Massage: ");
  content.toUpperCase();

  Serial.println ("Tempel Kartu");
  
  if (content == "xxxxxxx")
  {
    Serial.println ("Selamat Datang");
    delay(1000);
  }
    else{
      Serial.println("Kartu Belum Terdaftar");
    }
}
