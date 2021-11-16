//Inisialisasi

#include <OneWire.h>
#include <DallasTemperature.h>
int pinBuzzer = 5;
int sensorSuhu=2;
int R =3;
int Y =4;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode (pinBuzzer, OUTPUT);
  pinMode (R,OUTPUT);
  pinMode (Y,OUTPUT);

}

void loop() {
  // Baca Sensor
  sensors.requestTemperatures();
  float bacaSuhu=sensors.getTempCByIndex(0);

  //Print to Serial
  Serial.print("Suhu :");
  Serial.print(bacaSuhu);
  Serial.print(" C");
  Serial.println();//Enter

  //Logic
  if (bacaSuhu < 30){
  digitalWrite(pinBuzzer,LOW);
  digitalWrite(R,LOW);
  digitalWrite(Y,HIGH);
  delay(1000);
  }

  else if (bacaSuhu >= 31){
  digitalWrite(pinBuzzer,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(R,HIGH);
  delay(1000);
  }

}
