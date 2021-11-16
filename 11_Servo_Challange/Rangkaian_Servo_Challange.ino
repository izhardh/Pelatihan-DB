#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

String uidString;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int outServo=2;
int buzzer = 5;
int sensor1 = 6;
int kunci1 = LOW;


#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myservo;

void setup() {
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
  myservo.attach(outServo);
  
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
      myservo.write(180); //0-180
      delay(1000); //Jeda waktu perulagan seama 500 mili detik
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
       myservo.write(0); //0-180
      delay(1000); //Jeda waktu perulagan seama 500 mili detik
      myservo.write(90); //0-180
      delay(1000); //Jeda waktu perulagan seama 500 mili detik
      bunyibuzzergagal();
    }
  }

  int bacaSensor1 = digitalRead(sensor1);
  
  if (bacaSensor1 == 0 and kunci1 == 1){
  bunyibuzzeroke();
  lcd.clear();
  myservo.write(0); //0-180
  delay(1000); //Jeda waktu perulagan seama 500 mili detik
  lcd.setCursor(4,0); lcd.print("Palang");
  lcd.setCursor(4,1); lcd.print("Tertutup");
  Serial.println ("Palang Tertutup");
  Serial.println (" ");
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
