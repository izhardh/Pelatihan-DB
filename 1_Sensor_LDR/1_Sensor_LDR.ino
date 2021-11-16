int pinLDR      = PA4;
int pinLED      = PA0;
void setup() {
  
  Serial.begin(9600);
  pinMode(pinLDR,INPUT);
  pinMode(pinLED, OUTPUT);
}

void loop() {
  //Baca Data
  int bacaLDR=analogRead(pinLDR);
      //bacaLDR=map(bacaLDR,0,1024,0,255);

  // Print Serial
  Serial.print ("Nilai Print : ");
  Serial.print (bacaLDR);
  Serial.println(); //Untuk Enter

  //Logic
  analogWrite(pinLED,bacaLDR);
  }
  
