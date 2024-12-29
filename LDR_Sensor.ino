int lightPin=A0;
int lightVal;
int delaya=500;
int LEDPin=12;
int LEDPin2=13;

void setup() {
pinMode(lightPin,INPUT);
pinMode(LEDPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
lightVal=analogRead(lightPin);
if(lightVal>=500 && lightVal<=800){
  digitalWrite(LEDPin,HIGH);
  digitalWrite(LEDPin2,LOW);


}
if(lightVal>800){
  digitalWrite(LEDPin2,HIGH);
  digitalWrite(LEDPin,LOW);

}
else{
  digitalWrite(LEDPin,LOW);

}
Serial.println(lightVal);
delay(delaya);
}
