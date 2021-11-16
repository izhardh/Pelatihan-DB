//Download Library LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
  LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
//Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  lcd.begin();
  }
void loop() {
  //Program yang akan dijalankan berulang-ulang
  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(5,0); lcd.print("Welcome ");
  lcd.setCursor(5,1); lcd.print("Tempel Kartu");
  delay(1000); //Jeda waktu perulagan seama 1000 mili detik

  lcd.clear(); //Untuk Menghapus karakter pada LCD
  lcd.setCursor(5,0); lcd.print("Yuuhuuu ");
  lcd.setCursor(5,1); lcd.print("Gaskuun ");
  delay(1000); //Jeda waktu perulagan seama 1000 mili detik
}
