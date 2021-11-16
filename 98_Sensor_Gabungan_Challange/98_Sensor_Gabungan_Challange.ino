int pinFlame      =A0;
int pinPIR        = 3;
int pinLDR        = A1;
int pinBuzzer     = 5;
int R         = 9;

void setup() {
  Serial.print ("Sensor LDR");
  Serial.print ("Sensor Flame");
  Serial.println ("Sensor PIR");
  
  Serial.begin(9600);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(R,OUTPUT);
//  pinMode(Y,OUTPUT);
//  pinMode(G,OUTPUT);
}

void loop() {
  //Baca Data
  int bacaFlame=analogRead(pinFlame);
      bacaFlame=map(bacaFlame,1016,34,0,255);
  int bacaLDR=analogRead(pinLDR);
      bacaLDR=map(bacaLDR,19,902,0,255);
  int bacaPIR=analogRead(pinPIR);
 // Serial.print(bacaLD);
      // Fungsi MAP mengubah nilai dengan format (tampung, dataawal sensor, dataakhir sensor, nilaiawal ubah, nilai akhirubah)
  Serial.print("Nilai Flame: " + String (bacaFlame));
  Serial.println(" |Nilai LDR :" + String (bacaLDR));
  // Print Serial
//  Serial.print ("Nilai Flame :" bacaFlame);
//  Serial.println ("Nilai LDR :" bacaLDR);
//  Serial.print ("Nilai PIR :" bacaPIR);
  Serial.println(); //Untuk Enter

  //Logic
  analogWrite(R,bacaLDR);

  if (bacaFlame <= 20){
    digitalWrite(pinBuzzer,LOW);
    Serial.println ("AMAN");
    delay(1000);
    
  }
  else if (bacaFlame >= 21 and bacaFlame <=199){
    digitalWrite(pinBuzzer,HIGH);
    Serial.println ("WASPADA");
    delay(2000);
  }
  else {
    Serial.println ("BAHAYA");
    digitalWrite(pinBuzzer,HIGH);
    delay (2000);
  }
}  
