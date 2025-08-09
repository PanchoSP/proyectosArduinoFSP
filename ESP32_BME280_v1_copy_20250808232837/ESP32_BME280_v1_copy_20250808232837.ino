#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// SCL al 22 y SDA al 21 | 3.3V y GND Posterior (al lado del VIN)

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;  // I²C

void setup() {
  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  bool status = bme.begin(0x76);
  if (!status) {
    Serial.println("No se pudo detectar el sensor BME280 — revisa las conexiones o la dirección I²C");
    while (1);
  }
}

void loop() {
  Serial.print("Temperatura = ");
  Serial.print(bme.readTemperature());
  Serial.println(" °C");

  Serial.print("Humedad = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Presión = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Altitud ≈ ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.println();
  delay(2000);
}
