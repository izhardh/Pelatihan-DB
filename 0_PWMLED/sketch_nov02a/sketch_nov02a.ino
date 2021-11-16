void setup() {
  Serial.begin(9600);
  for (int i=2; i<=4; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  for (int i=0; i<=255; i++){
    analogWrite(3,i);
    //float volt=map(i,0,255,0,5); //Konversi Nilai PWM ke volt 0 - 255
    float volt=(5.0/255.0);
    float ia = i*volt;
    Serial.print("Volt :");
    Serial.println(ia);
    delay(30);
  }
  for (int i=255; i<0; i--){
    analogWrite(3,i);
    //float volt=map(i,0,255,0,5); //Konversi Nilai PWM ke volt 0 - 255
    float volt=(5.0/255.0);
    float ia = i*volt;
    Serial.print("Volt :");
    Serial.println(ia);
    delay(30);
  }

  
  }
