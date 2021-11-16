// Inisialisasi
int tombol1=2;
int sensor1=3;
int R=5;
int Y=6;
int G=7;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  digitalWrite(R,HIGH);
  Serial.print (" System Begin ");
  digitalWrite(R,HIGH);
}

void loop() {
  //Baca Data
  int bacaTombol1=digitalRead(tombol1);
  int bacaSensor1=digitalRead(sensor1);

  //Print Serial
//  Serial.print(" | Kondisi Tombol 1:"); Serial.print(bacaTombol1);
//  Serial.print(" | Kondisi Tombol 2:"); Serial.print(bacaTombol2);
//  Serial.print(" | Kondisi Tombol 3:"); Serial.print(bacaTombol3);
//  Serial.println();

  //Logic
  //Logic 1
  if (bacaTombol1==1){
    delay(500);
    Serial.print(" Selamat Datang, Ambil Tiket ");
    Serial.print(" Palang Dibuka ");
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    delay(1000);
    digitalWrite(Y,LOW);
    delay(100);
    digitalWrite(G,HIGH);
  }

  if (bacaSensor1==0){
    delay(500);
    Serial.print(" Palang Ditutup ");
    digitalWrite(G,LOW);
    digitalWrite(R,HIGH);
  }
}
