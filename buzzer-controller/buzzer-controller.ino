int buzzerPin = 7;
int soundDuration;
int silenceDuration;
int finishDuration;
String soundString;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);

  Serial.println("\nPLEASE ENTER SOUND DURATION (MS)  :");
  while (Serial.available() == 0);
  soundDuration = Serial.parseInt();
  Serial.println("PLEASE ENTER SILENCE DURATION (MS):");
  while (Serial.available() == 0);
  silenceDuration = Serial.parseInt();
  Serial.println("PLEASE ENTER FINISH DURATION (MS) :");
  while (Serial.available() == 0);
  finishDuration = Serial.parseInt();
  Serial.println("PLEASE ENTER SOUND STRING         :");
  while (Serial.available() == 0);
  soundString = Serial.readString();

  Serial.print("\nTHE INPUTS:\n->SOUND DURATION (MS)  : ");
  Serial.print(soundDuration);
  Serial.print("\n->SILENCE DURATION (MS): ");
  Serial.print(silenceDuration);
  Serial.print("\n->FINISH DURATION (MS) : ");
  Serial.print(finishDuration);
  Serial.print("\n->SOUND STRING         : ");
  Serial.println(soundString);
  Serial.println();
}

void loop() {
  while(1){
    for (int i = 0; i <soundString.length(); i++) {
      char c = soundString.charAt(i);
      
      if (c=='1') {
        digitalWrite(buzzerPin,HIGH);
      }
      else{
        digitalWrite(buzzerPin,LOW);
      }
      delay(soundDuration);
      digitalWrite(buzzerPin,LOW);
      delay(silenceDuration);
    }
    
  digitalWrite(buzzerPin,LOW);
  delay(finishDuration);
  Serial.println("String completed!");  
  }
}
