//int tombol = PA0;
int sensor = PA3;
int LDR = PA4;
int R = PA0;
int Ye = PA1;
int G = PA2;
int kunci = LOW;

void setup(){
  //pinMode(tombol,INPUT);
  pinMode(sensor,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Ye,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop(){
  //int bacaTombol = digitalRead(tombol);
  int bacaSensor = digitalRead(sensor);
  int bacaLDR = analogRead(LDR);
      bacaLDR = map(bacaLDR,0,1024,0,255);

  if (bacaSensor == 0 and kunci == 0){
    digitalWrite(R,HIGH);
    delay (500);
    kunci=1;
  }
  else if (bacaSensor == 0 and kunci == 1){
    digitalWrite(R,LOW);
    delay (500);
    kunci=0;
  }
    analogWrite(Ye,bacaLDR);
  }
//  else if (bacaTombol == 1){
//    delay(500);
//    Serial.print("Palang Ditutup");
//    digitalWrite(G,LOW);
//    digitalWrite(R,HIGH);
