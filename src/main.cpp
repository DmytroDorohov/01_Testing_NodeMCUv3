#include <Arduino.h>
#include <Project_OLED.h>
#include <Project_WiFi.h>

const String VERSION = "0.1"; // Version project
const int ADDR_ADS = 0x10;    // ADS1115 address on I2C
const int ADDR_BME = 0x10;    // BME280 address on I2C
const int ADDR_MQ = 0x10;     // MQ135 address on I2C
const int ADDR_RTC = 0x10;    // TinyRTC DS1307 address on I2C
const int ADDR_MEM = 0x10;    // TinyRTC AT24C address on I2C

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  logo(VERSION); // Show logo in start
  initWiFi();    // Start WiFi
}

void loop()
{
  delay(5000); // задержка
  // scanWire();   // сканирование I2C линии
  testingOLED();
}