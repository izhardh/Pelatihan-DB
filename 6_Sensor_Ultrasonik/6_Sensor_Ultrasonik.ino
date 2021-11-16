//Inisialisasi
#include <NewPing.h>

int triger = 7;
int echo = 6;
int R=3;
int Y=4;
int G=8;
int batas =400;//Max 400 cm
int pinBuzzer = 5;

NewPing cm(triger,echo,batas);

void setup() {
  Serial.begin(9600);
  pinMode (R,OUTPUT);
  pinMode (Y,OUTPUT);
  pinMode (G,OUTPUT);
  pinMode (pinBuzzer,OUTPUT);

}

void loop() {
  // Baca Sensor
  int bacaJarak=cm.ping_cm();
  
  //Print to Serial
  Serial.print("Data Jarak: ");
  Serial.print(bacaJarak);
  Serial.print(" cm ");
  Serial.println();//Enter
  delay(500); //Jeda Jarak 500 ml s

  //Logic
  if (bacaJarak <=20 and bacaJarak!=0){
    digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
    digitalWrite(pinBuzzer,HIGH);
    delay (100);
    digitalWrite(pinBuzzer,LOW);
    Serial.print("Berhenti ");
    
  }
  else if (bacaJarak >= 21 and bacaJarak <=70){
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    digitalWrite(G,LOW);
    digitalWrite(pinBuzzer,LOW);
    Serial.print("Bahaya ");
  }
  else{
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
    digitalWrite(pinBuzzer,LOW);
    Serial.print("Aman ");
  }
}
