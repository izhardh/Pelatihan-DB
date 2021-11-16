// Inisialisasi
int tombol1=PA3;
int tombol2=PA4;
int tombol3=PA5;
int R=PA0;
int Ye=PA1;
int G=PA2;
int kunci1 = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Ye,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  //Baca Data
  int bacaTombol1=digitalRead(tombol1);
  int bacaTombol2=digitalRead(tombol2);
  int bacaTombol3=digitalRead(tombol3);

  //Print Serial
  Serial.print(" | Kondisi Tombol 1:"); Serial.print(bacaTombol1);
  Serial.print(" | Kondisi Tombol 2:"); Serial.print(bacaTombol2);
  Serial.print(" | Kondisi Tombol 3:"); Serial.print(bacaTombol3);
  Serial.println();

  //Logic
  //Logic 1
  if(bacaTombol1==1 and kunci1==0){
    delay(500);
    digitalWrite(R,HIGH);
    kunci1=1;
    
  }else if(bacaTombol1==1 and kunci1==1){
    delay(500);
    digitalWrite(R,LOW);
    kunci1=0;
  }

//Logic 2
  if(bacaTombol2==1 and kunci1==0){
    delay(500);
    digitalWrite(Ye,HIGH);
    kunci1=1;
    
  }else if(bacaTombol2==1 and kunci1==1){
    delay(500);
    digitalWrite(Ye,LOW);
    kunci1=0;
  }
    
//  //Logic 3
  if(bacaTombol3==1 and kunci1==0){
    delay(500);
    digitalWrite(G,HIGH);
    kunci1=1;
    
  }else if(bacaTombol3==1 and kunci1==1){
    delay(500);
    digitalWrite(G,LOW);
    kunci1=0;
  }  
  }
