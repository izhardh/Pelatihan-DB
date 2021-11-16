#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#define B1 3 // Motor B pins
#define B2 6

int incomingByte = 0; // for incoming serial data
int input = 0;

String uidString;
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define A1 2 // Motor A pins
#define A2 10
#define B1 3 // Motor B pins
#define B2 6

int outServo=2;
int buzzer = 5;
int sensor1 = 7;
int kunci1 = LOW;


#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  
  Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  lcd.begin();
  pinMode(buzzer, OUTPUT);
  pinMode(sensor1, INPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  bunyibuzzeroke();
  Serial.println("Tempelkan Kartu");
  lcd.setCursor(5,0); lcd.print("Welcome ");
  lcd.setCursor(3,1); lcd.print("Tempel Kartu");

  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  
  // put your setup code here, to run once:

}

void loop() {

  //Serial.println(bacaSensor1);
  if ( mfrc522.PICC_IsNewCardPresent() and kunci1==0 ) {
    readRFID();
    Serial.print("Tag UID: ");
    Serial.println(uidString);
    if(uidString == "8A-37-5A-1A"){
      bunyibuzzeroke();

      analogWrite(B1, 225);
      //analogWrite(B2, 0);
      delay(100);
      digitalWrite(B1, LOW);
      //digitalWrite(B2, LOW);
      
      lcd.clear();
      lcd.setCursor(4,0); lcd.print("Silahkan");
      lcd.setCursor(5,1); lcd.print("Masuk");
      delay(1000);
      Serial.println("Berhasil");
      Serial.println("Gerbang Buka");
      lcd.clear(); //Untuk Menghapus karakter pada LCD
      delay(1000);
      Serial.println("Silahkan Masuk!");
      kunci1 = 1;
    }
    else if(uidString == "2F-3F-C9-95" ){
      bunyibuzzeroke();
      lcd.setCursor(5,0); lcd.print("Silahkan ");
      lcd.setCursor(3,1); lcd.print("Masuk");
      Serial.println("Berhasil");
      Serial.println("Gerbang Buka");
      delay(1000);
      Serial.println("Silahkan Masuk!");
      kunci1 = 1;
    }else{
      Serial.println("Gagal");
      lcd.setCursor(5,0); lcd.print("Daftar Dulu");
      bunyibuzzergagal();
    }
  }

  int bacaSensor1 = digitalRead(sensor1);
  
  if (bacaSensor1 == 0 and kunci1 == 1){
  bunyibuzzeroke();
  lcd.clear();
  delay(1000); //Jeda waktu perulagan seama 500 mili detik
  lcd.setCursor(4,0); lcd.print("Palang");
  lcd.setCursor(4,1); lcd.print("Tertutup");
  Serial.println ("Palang Tertutup");
  Serial.println (" ");
      //analogWrite(B1,0);
      analogWrite(B2, 255);
      delay(100);
      //digitalWrite(B1, LOW);
      digitalWrite(B2, LOW);
  delay(2000);
  Serial.println ("Tempelkan Kartu");
  kunci1=0;
}
  
}
  
  // put your main code here, to run repeatedly:
void readRFID(){
  mfrc522.PICC_ReadCardSerial();

  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
}


void bunyibuzzeroke(){
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
}

void bunyibuzzergagal(){
  digitalWrite(buzzer,LOW);
}
