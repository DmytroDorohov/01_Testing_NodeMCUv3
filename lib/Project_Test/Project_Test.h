/*
Описание библиотеки
*/

#ifndef Project_Test_h
#define Project_Test_h
#include <Arduino.h>

class TEST
{
public:
    TEST();          // TEST class constructor
    void scanWire(); // Scanning devices connected via I2C
}

#endif