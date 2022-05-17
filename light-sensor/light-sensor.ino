#define led 3 //3.Pinde LED olduğunu tanımlıyoruz
int LED_ACTIVATION_VALUE = 500;
int SERIAL_OUTPUT_FREQUENCY = 500;

int totalTime = 600;
void setup() {
 
  pinMode(led, OUTPUT); //LED'in çıkış elemanı olduğunu belirtiyoruz
  Serial.begin(9600); //9600 Baundluk bir seri haberleşme başlatıyoruz

}

void loop() {

  int isik = analogRead(A0)*100; //Işık değişkenini A0 pinindeki LDR ile okuyoruz
 
  delay(SERIAL_OUTPUT_FREQUENCY);

  if (isik > LED_ACTIVATION_VALUE) { //Okunan ışık değeri 900'den büyük ise
    Serial.println("LIGHT SENSOR: "); //Okunan değeri seri iletişim ekranına yansıtıyoruz
    Serial.println(isik); //Okunan değeri seri iletişim ekranına yansıtıyoruz
    Serial.println("LED STATUS: OFF");
    digitalWrite(led, LOW); //LED yanmasın
  }

  if (isik < LED_ACTIVATION_VALUE-50) { //Okunan ışık değeri 850'den küçük ise
    Serial.println("LIGHT SENSOR: "); //Okunan değeri seri iletişim ekranına yansıtıyoruz
    Serial.println(isik); //Okunan değeri seri iletişim ekranına yansıtıyoruz
    Serial.println("LED STATUS: ON");
    digitalWrite(led, HIGH); //LED yansın
  }

}
