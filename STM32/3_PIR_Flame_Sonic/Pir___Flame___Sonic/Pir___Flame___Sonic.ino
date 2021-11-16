#include <NewPing.h>


int R = PA0;
int Ye = PA1;
int G = PA2;
int PIR = PA5;
int Flame = PA6;
//int sonic = PA5;
int triger = PA3;
int echo = PA4;
int batas = 400;

NewPing cm(triger,echo,batas);

void setup() {
  Serial.begin (9600);
  pinMode (PIR, INPUT);
  pinMode (Flame, INPUT);
  //pinMode (sonic, INPUT);
  pinMode (R, OUTPUT);
  pinMode (Ye, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (PIR,INPUT);

  
  // put your setup code here, to run once:

}

void loop() {
int bacaJarak = cm.ping_cm();

    int bacaFlame = analogRead(Flame);
    bacaFlame = map(bacaFlame,4095,291,255,0);

    int bacaPIR = digitalRead(PIR);

    //Print Serial Flame
    Serial.print("Data Flame: ");
    Serial.print(bacaFlame);
    Serial.println();
  
  //Print Serial Jarak
  Serial.print("Data Jarak: ");
  Serial.print(bacaJarak);
  Serial.print(" cm ");
  Serial.println();

  //Logic Sonic

  if (bacaJarak <= 20 and bacaJarak!=0){
    digitalWrite (R,HIGH);
    digitalWrite (Ye,LOW);
    digitalWrite (G,LOW);
    Serial.print ("Berhenti");
  }else if (bacaJarak >= 21 and bacaJarak <= 70){
    digitalWrite (Ye,HIGH);
    digitalWrite (G,LOW);
    digitalWrite (R,LOW);
    Serial.print ("Hati-Hati");
  }else{
    digitalWrite (G,HIGH);
    digitalWrite (Ye,LOW);
    digitalWrite (R,LOW);
    Serial.print ("Aman");
  }
}

  //Logic Flame
//  if (bacaFlame <= 20){
//    digitalWrite (G,HIGH);
//    digitalWrite (Ye,LOW);
//    digitalWrite (R,LOW);
//    Serial.println ("AMAN");
//    delay (1000);
//  }
//  else if (bacaFlame >= 21 and bacaFlame <= 199){
//    digitalWrite (Ye,HIGH);
//    digitalWrite (R,LOW);
//    digitalWrite (G,LOW);
//    Serial.println ("Waspada");
//    delay (1000);
//  }
//  else{
//    digitalWrite (R,HIGH);
//    digitalWrite (G,LOW);
//    digitalWrite (G,LOW);
//    Serial.println ("Bahaya");
//    delay (1000);
//  }
//}
  
  //Logic PIR

//  if (bacaPIR==1){
//   digitalWrite(R,HIGH);
//    Serial.println ("Ada Maling");
//  }
//  else {
//    digitalWrite(R,LOW);
//    Serial.println ("Tidak Ada Maling");
//  }
