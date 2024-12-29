#include <ESP8266WiFi.h>
int port = 8888;
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
WiFiServer server (port);
const char *ssid = "Sadrusha"; 
const char *password = "Sad@1234"; 
int count=0;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password); +

  Serial.println("Connecting to Wifi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.print("Open Telnet and connect to IP: ");
  Serial.print(WiFi.localIP());
  Serial.print(" on port ");
  Serial.println(port);
}

void loop()
{
  int key;
  WiFiClient client = server.available();
  if (client)
  {
    if(client.connected())
    {
      Serial.println("Client Connected");
      while(client.connected())
      {
        while(client.available()>0)
        {
          Serial.write(client.read());
          Serial.print("Temperature (%): ");
          Serial.println((float)dht.readTemperature());
          Serial.print("Humidity (%): ");
          Serial.println((float)dht.readHumidity());
          
        }
        while(Serial.available()>0)
        {
          client.write(Serial.read());
        }
      }
      client.stop();
      Serial.println("Client disconnected");
    }
  }
}