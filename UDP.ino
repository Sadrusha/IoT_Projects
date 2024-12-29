#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#define SOCKET 8888  
#define BUFFERLEN 255
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
char inBUFFER[BUFFERLEN];   
char outBUFFER[BUFFERLEN];  
WiFiUDP UDP;
const char ssid[]= "Sadrusha";
const char password[]="Sad@1234";

void setup() {
Serial.begin(115200);
Serial.print("Trying to connect to Wifi");
Serial.print(ssid);

WiFi.begin(ssid,password);

while(WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print("\n");
  Serial.print("not Connected to Wifi Yet");
}
Serial.print("\n");
Serial.println("Successfully connected with Wifi");

Serial.print("Ip Address : ");
Serial.println(WiFi.localIP());
Serial.print("Mac Address of Board : ");
Serial.println(WiFi.macAddress());
Serial.print("Subnet Mask  : ");
Serial.println(WiFi.subnetMask());

Serial.print("Gateway IP  : ");
Serial.println(WiFi.gatewayIP());

if ( UDP.begin(SOCKET))
 {
  Serial.print("\n");
  Serial.print("Initialization is successful");
  }
 else 
  {
  Serial.print("Initialization is Failed");
  }
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() 
{

int packetsize = 0;  
packetsize = UDP.parsePacket();    
if (packetsize)
{
  UDP.read(inBUFFER,BUFFERLEN);    
  inBUFFER[packetsize] = '\0' ; 
  if(strcmp("DATA",inBUFFER)==0)
  {
    digitalWrite(LED_BUILTIN,LOW);
    Serial.print("Temperature(C):");
    Serial.println((float)dht.readTemperature());
    Serial.print("Humidity(%):");
    Serial.println((float)dht.readHumidity());
  }   
  if(strcmp("NODATA",inBUFFER)==0)
  {
    digitalWrite(LED_BUILTIN,HIGH);
  }
  Serial.print(packetsize);  
  Serial.println("bytes");

  Serial.print("Contents:"); 
  Serial.println(inBUFFER);   
  Serial.print("From IP ");  
  Serial.println(UDP.remoteIP());  
  Serial.print("From Port ");   
  Serial.println(UDP.remotePort()); 

 }
}