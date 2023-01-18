/*
Описание библиотеки
*/

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Project_OLED.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    // Reset pin # (or -1 if sharing Arduino reset pin)
#define ADDR_OLED 0x3C   // Oled address on I2C

Adafruit_SSD1306 oled = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void logo(String ver)
{
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  oled.begin(SSD1306_SWITCHCAPVCC, ADDR_OLED);
  oled.clearDisplay();
  oled.setTextSize(3);
  oled.setTextColor(WHITE);
  oled.setCursor(20, 10);
  oled.println("Micrik");
  oled.setTextSize(2);
  oled.setCursor(40, 10);
  oled.println("Project 01");
  oled.setTextSize(1);
  oled.setCursor(50, 10);
  oled.print("Version ");
  oled.print(ver);
  oled.display();
  delay(2000);
}

void showInitWifi(int8_t i)
{
  switch (i)
  {
  case 1:
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 10);
    oled.println("Conecting WiFi");
    oled.display();
    break;
  case 2:
    oled.print(".");
    oled.display();
    break;
  case 3:
    oled.println();
    oled.print("Conected: IP = ");
    oled.println(WiFi.localIP());
    oled.println();
    oled.display();
  default:
    oled.println("ERROR Conecting");
    oled.display();
    break;
  }
}

void testingOLED(void)
{
  oled.clearDisplay();
  for (int16_t i = 0; i < oled.height() / 2; i += 2)
  {
    oled.drawRect(i, i, oled.width() - 2 * i, oled.height() - 2 * i, WHITE);
    oled.display(); // Update screen with each newly-drawn rectangle
    delay(1);
  }
}