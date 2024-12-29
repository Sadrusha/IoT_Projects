int relay=7;
int BUTTON_PIN=8;
int push_button;

void setup() {
  // put your setup code here, to run once:
pinMode(relay,OUTPUT);
pinMode(BUTTON_PIN,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
push_button=digitalRead(BUTTON_PIN);
if(push_button==0)
{
  digitalWrite(relay,HIGH);
}
else{
  digitalWrite(relay,LOW);
}
}
