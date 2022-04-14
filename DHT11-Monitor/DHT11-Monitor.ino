// include the library code:
#include <LiquidCrystal.h>
#include "DHT.h"
boolean flag = true;
boolean state = true;

// set the DHT Pin
#define DHTPIN 8
const int buttonPin = 13;
int buttonState = 0; 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(buttonPin, INPUT);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  dht.begin(); 
}

void loop() {
  String hum = "";     // empty string
  String tem = "";     // empty string
  delay(500);
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    if (flag==true){
      flag = false;
    }
    else {
      flag = true;
    }
  }
  
  // read humidity
  float h = dht.readHumidity();
  float f;
  if (flag==true){
    //read temperature in Fahrenheit
    f = dht.readTemperature(true);
  }
  else {
    //read temperature in Celcius
    f = dht.readTemperature();
  }
  
  if (isnan(h) || isnan(f)) {
    lcd.print("ERROR");
    return;
  }

  if(flag==false) {
    
    hum.concat(h); 
    hum.replace('.',',');
   
    tem.concat(f); 
    tem.replace('.',',');
  }
  

  if (flag == true){
    // Print a message to the LCD.
    lcd.setCursor(0, 0);
    lcd.print("TEM(F):");
    lcd.setCursor(14, 0);
    lcd.print("EN");
    lcd.setCursor(0, 1);
    lcd.print("HUM(%):");
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("SIC(C):");
    lcd.setCursor(14, 0);
    lcd.print("TR");
    lcd.setCursor(0, 1);
    lcd.print("NEM(%):");
  }

 if (flag == true) {
    if(h>100){
      lcd.setCursor(7, 0);
      lcd.print(f); 
    }
    else{
      lcd.setCursor(8, 0);
      lcd.print(f); 
    }
  
    if(f>100){
      lcd.setCursor(7, 1);
      lcd.print(h); 
    }
    else{
      lcd.setCursor(8, 1);
      lcd.print(h); 
    }
 }
 else {
    if(h>100){
      lcd.setCursor(7, 0);
      lcd.print(tem); 
    }
    else{
      lcd.setCursor(8, 0);
      lcd.print(tem); 
    }
  
    if(f>100){
      lcd.setCursor(7, 1);
      lcd.print(hum); 
    }
    else{
      lcd.setCursor(8, 1);
      lcd.print(hum); 
    }
 }
}
