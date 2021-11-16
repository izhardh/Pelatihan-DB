//Librarry yang digunakan
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>


//Variable Baru
#define SS_PIN PB11 //SDA
#define RST_PIN PB0 //Reset
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup (){
  // Fungsionalitas PIN MCU
  Serial.begin(115200); // Baudrate yang digunakan
  SPI.begin(); // Initiate SPI Begin
  mfrc522.PCD_Init(); // Initiate MFRC522
  lcd.begin();
  Serial.print ("Mulai");

  //Program yang akan dijalankan berulang-ulang
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(5,0); lcd.print("Welcome ");
  lcd.setCursor(2,1); lcd.print("Tempel Kartu");
}

void loop (){
  // Program yang diulang-ulang
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  // Pilihan satu kartu
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}

  // Show UID on Serial Monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ""));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content == "8A375A1A") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Selamat datang");
    delay(1000);
    lcd.clear(); //Untuk Menghapus karakter pada LCD
    lcd.setCursor(5,0); lcd.print("Selamat ");
    lcd.setCursor(5,1); lcd.print(" Datang ");
    delay(3000);
    
  }else{
    Serial.println("Kartu Belum Terdaftar!");
  }
  Serial.println("Tempelkan Kartu!");
  delay(500); //Jeda waktu perulagan seama 500 mili detik
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(5,0); lcd.print("Welcome ");
  lcd.setCursor(5,1); lcd.print("Tempel Kartu");
}
