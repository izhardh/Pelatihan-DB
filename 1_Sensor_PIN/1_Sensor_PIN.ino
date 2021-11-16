int pinPIR      = PA6;
int pinBuzzer   = 5;
void setup() {
  
  Serial.begin(9600);
  pinMode(pinPIR,INPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  //Baca Data
  int bacaPIR=digitalRead(pinPIR);

  // Print Serial
  Serial.print ("Nilai Print : ");
  Serial.print (bacaPIR);
  Serial.println(); //Untuk Enter
}
//  //Logic
//  if (bacaPIR==1){
//    digitalWrite(pinBuzzer,HIGH);
//    delay(100);
//    digitalWrite(pinBuzzer,LOW);
//    delay(10000);
//    Serial.println ("Ada Maling");
//  }
//  digitalWrite(pinBuzzer,LOW);
//  }
