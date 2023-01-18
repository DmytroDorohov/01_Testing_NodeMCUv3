/*
Описание библиотеки
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Project_OLED.h>
#include <Project_WiFi.h>

const char *WIFI_SSID = "TP-Link_D445"; // WiFi login
const char *WIFI_PASS = "40581330";     // WiFi password

void initWiFi(void)
{
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  showInitWiFi(0);
  for (int i = 1; i <= 20; i++)
  {
    showInitWiFi(1);
    delay(250);
    if (WiFi.status() == WL_CONNECTED)
      break;
    else if (i == 20)
    {
      showInitWiFi(20);
      return;
    }
  }
  showInitWiFi(2);
}