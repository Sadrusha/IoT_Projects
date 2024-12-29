#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(7, OUTPUT); // To provide power supply to DHT
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  delay(5000);
  int chk = dht.read();  // Corrected syntax for reading from DHT sensor
  digitalWrite(7, HIGH);
  Serial.print("Humidity(%): ");
  Serial.println((float)dht.readHumidity(), 2);  // Corrected syntax for humidity
  Serial.print("Temperature (C): ");
  Serial.println((float)dht.readTemperature(), 2);  // Corrected syntax for temperature
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor");
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Temperature");
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h);
  display.print("%");
  display.display();
}