#include <Arduino.h>

const int gpioInPin = 5;
const int gpioOutPin = 10;


const int THRESHOLD_DARK = 1500;  
const int THRESHOLD_LIGHT = 2500;  

void setup() {
  Serial.begin(115200);
  
  pinMode(gpioOutPin, OUTPUT);
  digitalWrite(gpioOutPin, LOW);
}

void loop() {
  // КРОК 1: Зчитати значення ADC з піна GPIO IN
  int adcValue = analogRead(gpioInPin);
  
  Serial.print("Значення ADC: ");
  Serial.println(adcValue);

  // КРОК 2 та 3: Порівняти значення з порогами (Гістерезис)
  if (adcValue < THRESHOLD_DARK) {
    digitalWrite(gpioOutPin, HIGH);
  } 
  else if (adcValue > THRESHOLD_LIGHT) {
    digitalWrite(gpioOutPin, LOW);
  }

  delay(200); 
}