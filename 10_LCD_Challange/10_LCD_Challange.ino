#include <SPI.h>
#include <MFRC522.h>

String uidString;

int buzzer = 5;
int sensor1 = 6;
int kunci1 = LOW;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor1, INPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  bunyibuzzeroke();
  Serial.println("Tempelkan Kartu");
  
  // put your setup code here, to run once:

}

void loop() {

  //Serial.println(bacaSensor1);
  if ( mfrc522.PICC_IsNewCardPresent() and kunci1==0 ) {
    readRFID();
    Serial.print("Tag UID: ");
    Serial.println(uidString);
    if(uidString == "8A-B0-C1-15"){
      bunyibuzzeroke();
      Serial.println("Berhasil");
      Serial.println("Gerbang Buka");
      delay(1000);
      Serial.println("Silahkan Masuk!");
      kunci1 = 1;
    }
    else if(uidString == "2F-3F-C9-95" ){
      bunyibuzzeroke();
      Serial.println("Berhasil");
      Serial.println("Gerbang Buka");
      delay(1000);
      Serial.println("Silahkan Masuk!");
      kunci1 = 1;
    }else{
      Serial.println("Gagal");
      bunyibuzzergagal();
    }
  }

  int bacaSensor1 = digitalRead(sensor1);
  
  if (bacaSensor1 == 0 and kunci1 == 1){
  bunyibuzzeroke();
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
