
unsigned short int increment;
unsigned short int waitTime;
unsigned short int counter = 0;

unsigned short int led1 = 1;
unsigned short int led2 = 2;
unsigned short int led3 = 4;
unsigned short int led4 = 8;
unsigned short int led5 = 16;

int led1_p = 2;
int led2_p = 3;
int led3_p = 4;
int led4_p = 5;
int led5_p = 6;

void increase(){
  
  
  while(1){
    if((counter & led1) == led1){
      digitalWrite(led1_p, HIGH);
    }
    else{
      digitalWrite(led1_p, LOW);
    }
    if((counter & led2) == led2){
      digitalWrite(led2_p, HIGH);
    }
    else{
      digitalWrite(led2_p, LOW);
    }
    if((counter & led3) == led3){
      digitalWrite(led3_p, HIGH);
    }
    else{
      digitalWrite(led3_p, LOW);
    }
    if((counter & led4) == led4){
      digitalWrite(led4_p, HIGH);
    }
    else{
      digitalWrite(led4_p, LOW);
    }
    if((counter & led5) == led5){
      digitalWrite(led5_p, HIGH);
    }
    else{
      digitalWrite(led5_p, LOW);
    }
    
    counter = ( counter + increment)% 32;
      
     delay(waitTime);
    
  }
}


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led1_p, OUTPUT);
  pinMode(led2_p, OUTPUT);
  pinMode(led3_p, OUTPUT);
  pinMode(led4_p, OUTPUT);
  pinMode(led5_p, OUTPUT);
  Serial.begin(9600);
}


void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("\nPlease enter increment value:");
  while (Serial.available() == 0);
  increment = Serial.parseInt();
  if(increment >= 1 && increment <= 31){
    while(1){
      Serial.print("\nPlease enter wait time value(ms):");
      while (Serial.available() == 0);
      waitTime = Serial.parseInt();
      if(waitTime >=1 && waitTime <= 10000){
        increase();
      }
      Serial.print("\nInvalid Value please enter again.");
    }
  }
  Serial.print("\nInvalid Value please enter again.");
}
