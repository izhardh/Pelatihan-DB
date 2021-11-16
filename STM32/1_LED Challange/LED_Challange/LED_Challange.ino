int R = PA1;
int Ye = PA2;
int G =  PA3;
int tombol1 = PA4;
int tombol2 = PA5;
int tombol3 = PA6;

void setup() {
  pinMode (R, OUTPUT);
  pinMode (Ye, OUTPUT);
  pinMode (G, OUTPUT);
  pinMode (tombol1, INPUT);
  pinMode (tombol2, INPUT);
  pinMode (tombol3, INPUT);
}

void loop() {
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);
  int bacaTombol3=digitalRead(tombol3);

  Serial.print(" | Kondisi Tombol 1:"); Serial.print(bacaTombol1);
  Serial.print(" | Kondisi Tombol 2:"); Serial.print(bacaTombol2);
  Serial.print(" | Kondisi Tombol 3:"); Serial.print(bacaTombol3);
  Serial.println();


  //Logic1
  if (bacaTombol1 == 1){
    digitalWrite(R,HIGH);
  }
  else{
    digitalWrite(R,LOW);
  }
  if (bacaTombol2 == 1){
    digitalWrite(Ye,HIGH);
  }
  else{
    digitalWrite(Ye,LOW);
  }
  if (bacaTombol3 == 1){
    digitalWrite (G,HIGH);
  }
  else{
    digitalWrite (G,LOW);
  }
}
