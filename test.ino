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
  pinMode(2, INPUT_PULLUP); 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  analogWrite(6,255); 

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