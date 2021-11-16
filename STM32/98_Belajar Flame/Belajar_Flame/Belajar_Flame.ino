// Inisialize Pin Mode
int flame = PA5;

void setup (){
  Serial.begin (9600);
  pinMode (flame, INPUT);
}

void loop (){
  // Deskripsi Pin Mode
  Serial.print (" Welcome ");
  Serial.println();
  int bacaFlame = analogRead (flame);
      bacaFlame = map(bacaFlame,4096,0,0,255);
  Serial.print ("Nilai Flame: ");
  Serial.print (bacaFlame);
  Serial.println();
}
