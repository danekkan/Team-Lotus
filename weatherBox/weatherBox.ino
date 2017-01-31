/*
 * Example code for SHT1x or SHT7x sensors demonstrating blocking calls
 * for temperature and humidity measurement in the setup routine and
 * non-blocking calls in the main loop.  The pin 13 LED is flashed as a
 * background task while temperature and humidity measurements are made.
 */

#include <Sensirion.h>
const uint8_t dataPin =  9;              // SHT serial data
const uint8_t sclkPin =  8;              // SHT serial clock
float temperature, humidity;
uint16_t rawData;
Sensirion sht = Sensirion(dataPin, sclkPin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  sht.measTemp(&rawData);                // sht.meas(TEMP, &rawData, BLOCK)
  Serial.println(rawData);
  temperature = sht.calcTemp(rawData);
  sht.measHumi(&rawData);                // sht.meas(HUMI, &rawData, BLOCK)
  humidity = sht.calcHumi(rawData, temperature);
  logData();
  delay(2500);
}

void logData() {
  Serial.print("Temperature = ");   Serial.print(temperature);
  Serial.print(" C, Humidity = ");  Serial.print(humidity);
  Serial.println(" ");
}
