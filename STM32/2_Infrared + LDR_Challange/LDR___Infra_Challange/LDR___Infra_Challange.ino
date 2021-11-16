int R = PA0 ;
int Ye = PA1;
int G = PA2;
int sensor = PA3;
int LDR = PA4;
int kunci = LOW;


void setup() {
  pinMode (R, OUTPUT);
  pinMode (Ye, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (sensor, INPUT);
  pinMode (LDR, INPUT);
}


void loop() {
  int bacaSensor = digitalRead(sensor);
  int bacaLDR = analogRead (LDR);
      bacaLDR = map(bacaLDR,2380,4095,0,255);
  Serial.begin (115200);
  Serial.print ("Nilai Print : ");
  Serial.print (bacaLDR);
  Serial.println(); //Untuk Enter
      
  if (bacaSensor == 0 and kunci == 0){
    kunci =1;
  }else if (bacaSensor == 0 and kunci == 1){
    kunci = 0;
  }
  
  if (bacaLDR >= 0 and bacaLDR <= 100 and kunci == 1){
      digitalWrite(G,HIGH);
  }else {
    digitalWrite(G,LOW);
   }    
    if (bacaLDR >= 101 and bacaLDR <= 200 and kunci == 1){
      digitalWrite(Ye,HIGH);
  }else {
    digitalWrite(Ye,LOW);
    }
    if (bacaLDR >= 201 and bacaLDR <= 250 and kunci == 1){
      digitalWrite(R,HIGH);
  }else {
    digitalWrite(R,LOW);
    }
}
