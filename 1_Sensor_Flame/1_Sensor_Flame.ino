int pinFlame      = PA1;
int pinBuzzer      =PA2;
int R         = 2;
int Y         = 3;
int G         = 4;

void setup() {
  
  Serial.begin(9600);
  pinMode(pinFlame,INPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  //Baca Data
  int bacaFlame=analogRead(pinFlame);
      bacaFlame=map(bacaFlame,1023,0,0,255);
      // Fungsi MAP mengubah nilai dengan format (tampung, dataawal sensor, dataakhir sensor, nilaiawal ubah, nilai akhirubah)

  // Print Serial
  Serial.print ("Nilai Print : ");
  Serial.print (bacaFlame);
  Serial.println(); //Untuk Enter

  //Logic
  if (bacaFlame <= 20){
    digitalWrite(pinBuzzer,LOW);
    digitalWrite(G,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(R,LOW);
    Serial.println ("AMAN");
    delay(1000);
    
  }
  else if (bacaFlame >= 21 and bacaFlame <=199){
    digitalWrite(pinBuzzer,HIGH);
    digitalWrite(Y,HIGH);
     digitalWrite(G,LOW);
    digitalWrite(R,LOW);
    Serial.println ("WASPADA");
    delay(2000);
  }
  else {
    Serial.println ("BAHAYA");
    digitalWrite(pinBuzzer,HIGH);
    digitalWrite(R,HIGH);
    digitalWrite(Y,LOW);
    digitalWrite(G,LOW);
    delay (2000);
  }
}  
