#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 4     // DHT11 data pin is connected to Arduino #4
#define DHTTYPE DHT11 // DHT sensor type

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial mySerial(3, 2); // HC-05 Tx & Rx is connected to Arduino #3 & #2

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  dht.begin();
  Serial.println("Initializing...");
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  Serial.println();
  int chk = dht.read(DHTPIN);  //  for reading from DHT sensor
  Serial.print("Humidity (%): ");
  Serial.println((float)dht.readHumidity(), 2);  //  for humidity
  Serial.print("Temperature (C): ");
  Serial.println((float)dht.readTemperature(), 2);  //  for temperature

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  mySerial.print("T");
  mySerial.print(temperature);
  mySerial.print("H");
  mySerial.print(humidity);
  mySerial.print(";");
  delay(2000);  // delay function
}
