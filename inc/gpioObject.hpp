#pragma once

#include <string>
#include <gpiod.hpp>
#include <iostream>

class gpioObject
{

private:
    int _gpioValue;
    int _gpioNumber;
    gpiod::line _line;
    gpiod::chip _chip;
    int _direction;
    std::string _lineName;

public:
    gpioObject(gpiod::chip chip, int gpioNumber, int gpioValue, int dir);
    ~gpioObject();
    int getGpioValue();
    void setGpioValue(int gpioValue);
    void setGpioDirection(int direction);
    int getGpioDirection();
    std::string getGpioName() 
    { 
        return _lineName; 
    }
};
