// Librarry yang digunakan
#include <LiquidCrystal_I2C.h>

// Inisialize Pin Mode
int flame = PA5;

// Inisialize Pembuatan Variable
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup (){
  Serial.begin (115200);
  pinMode (flame, INPUT);
  lcd.begin();
}

void loop (){
  // Deskripsi Pin Mode
  int bacaFlame = analogRead (flame);
      bacaFlame = map(bacaFlame,4096,0,0,255);

  Serial.print ("Nilai Flame: ");
  Serial.print (bacaFlame);
  Serial.println();
  
  if (bacaFlame > 100){
    lcd.clear();
    lcd.setCursor(5,0); lcd.print (" Ada ");
    lcd.setCursor(5,1); lcd.print(" Api ");
    delay (1000);
  }
  else{
    lcd.clear();
    lcd.setCursor(5,0); lcd.print(" Aman ");
    lcd.setCursor(5,1); lcd.print(" Jaya ");
    delay (1000);
  }
}
