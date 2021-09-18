#include "Configurations.h"

volatile int liczba;
bool przod;
void ISR_CYK()
{
  liczba++;
  Serial.println(liczba);
}

void setup() {

  przod=true;
  liczba = 0;
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), ISR_CYK,RISING );
  pinMode(WEJCIE_ENK1, INPUT_PULLUP); 
  pinMode(WYJSCIE_SIL1_1,OUTPUT);
  pinMode(WYJSCIE_SIL1_2,OUTPUT);
  pinMode(WYJSCIE_SIL1_PWM,OUTPUT);
  analogWrite(WYJSCIE_SIL1_PWM,255); 

}

void loop() {
  if(przod)
  {
  digitalWrite(4,HIGH); 
  digitalWrite(3,LOW); 
  }

  if(liczba>=1000)
  {
    digitalWrite(3,HIGH); 
    digitalWrite(4,HIGH); 
    przod=false;
    liczba=0;
  }
}