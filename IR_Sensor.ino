const int IRsensor =A0;
int val=0;
void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(IRsensor, INPUT);

}

void loop() {
if(digitalRead(IRsensor)==HIGH)
{
  digitalWrite(13,LOW);
}
else{
  digitalWrite(13,HIGH);
}
val=analogRead(IRsensor);
Serial.println(val);
delay(1000);

}
