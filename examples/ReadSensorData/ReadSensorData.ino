#include <I2CSoilMoistureSensor.h>
#include <Wire.h>

I2CSoilMoistureSensor sensor;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  sensor.begin(); // reset sensor
  delay(1000); // give some time to boot up
  Serial.print("I2C Soil Moisture Sensor Address: ");
  Serial.println(sensor.getAddress(),HEX);
  Serial.print("Sensor Firmware version: ");
  Serial.println(sensor.getVersion(),HEX);
  Serial.println();
}

void loop() {
  while (sensor.isBusy()) delay(50); // available since FW 2.3
  Serial.print("Soil Moisture Capacitance: ");
  Serial.print(sensor.getCapacitance()); //read capacitance register
  Serial.print(", Temperature: ");
  Serial.print(sensor.getTemperature()/(float)10); //temperature register
  Serial.print(", Light: ");
  Serial.println(sensor.getLight(true)); //request light measurement, wait and read light register
  sensor.sleep(); // available since FW 2.3
}
