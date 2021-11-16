#include <NewPing.h>

int triger  = PA3;
int echo    = PA4;
int R       = PA0;
int Ye      = PA1;
int G       = PA2;
int batas   = 400;//Max 400 cm
int flame   = PA6;
int kunci = LOW;
NewPing cm(triger,echo,batas);

void setup() {

  Serial.begin (9600);
  pinMode (R,OUTPUT);
  pinMode (Ye,OUTPUT);
  pinMode (G,OUTPUT);
  pinMode (flame,INPUT);
  
  // put your setup code here, to run once:

}

void loop() {

  int bacaJarak = cm.ping_cm();

  int bacaFlame = digitalRead (flame);

  //Print Serial Sonic
  Serial.print ("Jarak :");
  Serial.print (bacaJarak);
  Serial.print (" cm");
  Serial.println();
  
  // put your main code here, to run repeatedly:

  if(bacaFlame == 0 and kunci == 0 ){
  kunci = 1;
  delay (1000);
  }
  else if(bacaFlame == 0 and kunci == 1){
  kunci = 0;
  delay (1000);
  }

  Serial.print ("Kunci :");
  Serial.print (kunci);
  Serial.println();

  Serial.print ("Flame :");
  Serial.print (bacaFlame);
  Serial.println ();
  
  if(bacaJarak <= 100 and bacaJarak!=0 and kunci == 1 ){
    digitalWrite (R,HIGH);
    digitalWrite (Ye,HIGH);
    digitalWrite (G,HIGH);
    delay (100);
    digitalWrite (R,LOW);
    digitalWrite (Ye,LOW);
    digitalWrite (G,LOW);
    delay (100);
  }

  else if(bacaJarak >= 101 and bacaJarak <= 200 and kunci == 1 ){
    digitalWrite (R,HIGH);
    digitalWrite (Ye,HIGH);
    digitalWrite (G,HIGH);
    delay (1000);
    digitalWrite (R,LOW);
    digitalWrite (Ye,LOW);
    digitalWrite (G,LOW);
    delay (1000);
  }
  else if (bacaJarak >= 201 and bacaJarak <= 400 and kunci == 1){
   digitalWrite (R,HIGH);
   delay (100);
   digitalWrite (R,LOW);
   delay (100);
   digitalWrite (Ye,HIGH);
   delay (100);
   digitalWrite (Ye,LOW);
   delay (100);
   digitalWrite (G,HIGH);
   delay (100);
   digitalWrite (G,LOW);
   delay (100);
   digitalWrite (Ye,HIGH);
   delay (100);
   digitalWrite (Ye,LOW);
   delay (100);
    
  }
}
