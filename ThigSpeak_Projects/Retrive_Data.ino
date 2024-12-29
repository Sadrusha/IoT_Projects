#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
const char ssid[]="Sadrusha";
const char pass[]="Sad@1234";
WiFiClient client;
unsigned long counterChannelNumber=2411957;
const char * myCounterReadAPIkey="TFHADRY554N1LPQS";
const int FieldNumber1=1;
const int FieldNumber2=2;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.mode(WIFI_STA);
ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
if(WiFi.status()!=WL_CONNECTED)
{
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println("...");
  while(WiFi.status()!=WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    delay(5000);
  }
  Serial.println("Connected to WiFi Successfully");

}
float temp=ThingSpeak.readLongField(counterChannelNumber,FieldNumber1,myCounterReadAPIkey);
int statusCode=ThingSpeak.getLastReadStatus();
if(statusCode==200)
{
  Serial.print("Temperature");
  Serial.println(temp);
}
else
{
  Serial.println("Unable to read channel/No internet connection");
}
delay(100);

long humidity=ThingSpeak.readLongField(counterChannelNumber,FieldNumber2,myCounterReadAPIkey);
if(statusCode ==200)
{
  Serial.print("Humidity");
  Serial.println(humidity);
}
else
{
  Serial.println("Unable to read channel/No internet connection");
}
}