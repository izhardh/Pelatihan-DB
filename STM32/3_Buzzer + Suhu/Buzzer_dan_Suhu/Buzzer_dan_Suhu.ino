// Kalo sensor Flame pakai librarry

#include <OneWire.h>
#include <DallasTemperature.h>

int buzzer = PA0;
int suhu = PA1;
int R = PA2;
int Ye = PA3;
OneWire oneWire(suhu);
DallasTemperature sensors(&oneWire);

void setup (){

  //Jika memakai Librarry maka tidak usah deklarasi pinMode
  //Namun ditambah "sensors.begin()"
  
  Serial.begin(9600);
  sensors.begin();
  pinMode (buzzer,OUTPUT);
  pinMode (R,OUTPUT);
  pinMode (Ye,OUTPUT);
}

void loop(){
  //baca Sensor
  sensors.requestTemperatures();
  float bacaSuhu=sensors.getTempCByIndex(0); // Harus ditambah template mengikuti Librarry yang digunakan

  //Serial Print
  Serial.print ("suhu :");
  Serial.print (bacaSuhu);
  Serial.print (" C");
  Serial.println ();//Enter

  //Logic
  if (bacaSuhu < 30){
  digitalWrite (buzzer,LOW);
  digitalWrite (R,LOW);
  digitalWrite (Ye,HIGH);
  delay(1000);
  }
  //Logic 2
  else if (bacaSuhu >= 31){
    digitalWrite (buzzer,HIGH);
    digitalWrite (R,LOW);
    digitalWrite (Ye,HIGH);
    delay(1000);
  }
}
