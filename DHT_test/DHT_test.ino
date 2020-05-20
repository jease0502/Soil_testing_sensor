#include "DHT.h"
#define DHTPIN 2   
#define DHTTYPE DHT11
const int sensorPin=8;
  

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  pinMode(sensorPin,INPUT);
  dht.begin();
  }

void loop() {
  delay(2000);
  int moist;
  moist = analogRead(sensorPin);
  Serial.print("濕度");
  Serial.println(1023-moist);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
    }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("*C\t");
  Serial.print(f);
  Serial.print("*F\n");
  }
