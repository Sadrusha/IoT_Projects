#include "DHT.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SPI.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float Humidity;
float Temperature;

const char* ssid = "Sadrusha";
const char* password = "Sad@1234";

char server[] = "192.168.47.139"; // eg: 192.168.0.222

WiFiClient client;

void setup() 
{
  Serial.begin(115200);
  delay(10);
  dht.begin();

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("erver started");
  delay(1000);
  Serial.println("connecting...");
}
void loop()
{
 Humidity = dht.readHumidity(); 
 Temperature = dht.readTemperature();
 Sending_To_phpmyadmindatabase(); 
 delay(10000); // interval
}
void Sending_To_phpmyadmindatabase() //CONNECTING WITH MYSQL
{
if (client.connect(server, 80)) {
Serial.println("connected"); // Make a HTTP request:
String url = "GET /dht11_project/test_data.php?Humidity=";
url.concat(Humidity) ;
url.concat("&Temperature="); 
url.concat(Temperature);
Serial.print(url);
client.print(url);
client.println();
} else {
Serial.println("Connection to server failed");
}
}