// Inisialisasi
int tombol1=2;
int tombol2=3;
int tombol3=4;
int R=5;
int Y=6;
int G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  //Baca Data
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol1);
  int bacaTombol3=digitalRead(tombol3);

  //Print Serial
  Serial.print(" | Kondisi Tombol 1:"); Serial.print(bacaTombol1);
  Serial.print(" | Kondisi Tombol 2:"); Serial.print(bacaTombol2);
  Serial.print(" | Kondisi Tombol 3:"); Serial.print(bacaTombol3);
  Serial.println();

  //Logic
  //Logic 1
  if(bacaTombol1==1){
    digitalWrite(R,HIGH);
  }else{
    digitalWrite(R,LOW);
  }

  //Logic 2
  if(bacaTombol2==1){
    digitalWrite(Y,HIGH);
  }else{
    digitalWrite(Y,LOW);
  }

  //Logic 3
  if(bacaTombol3==1){
    digitalWrite(G,HIGH);
  }else{
    digitalWrite(G,LOW);
  }
}  
