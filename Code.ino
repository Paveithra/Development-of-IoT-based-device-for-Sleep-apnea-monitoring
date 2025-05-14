#include <DHT.h>

#define DHTPIN 2       // DHT11 data pin
#define DHTTYPE DHT11  // DHT 11
#define ECG_PIN A1    // Define the pin where the ECG sensor output is connected

DHT dht(DHTPIN, DHTTYPE);
int soundPin = A0;   // LM32 sound sensor output pin

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  dht.begin();         // Initialize DHT sensor
}

void loop() {
  // Read DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  // Read sound level
  int soundLevel = analogRead(soundPin);

  // Read ECG sensor value
  int ecgValue = analogRead(ECG_PIN);
  
  // Print values to Serial Monitor
  Serial.print("Humidity: "); Serial.print(h);
  Serial.print("%, Temperature: "); Serial.print(t);
  Serial.print("°C, Sound Level: "); Serial.print(soundLevel);
  Serial.print(", ECG Value: "); Serial.println(ecgValue);

  delay(2000); // Delay before next reading
}
