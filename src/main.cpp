#include <Arduino.h>
#include <ESP8266WiFi.h>

const char *ssid = "TP-Link_D445";
const char *password = "40581330";

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Conecting...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Conected: IP = ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // мигание светодиодом
  delay(1000);                                          // задержка
}