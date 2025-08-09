#pragma once

#include <string>
#include <gpiod.hpp>

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
    gpioObject(gpiod::chip chip, int gpioNumber, int dir);
    ~gpioObject();
    int getGpioValue();
    int setGpioValue(int gpioValue);
    void setGpioDirection(int direction);
    int getGpioDirection();
    std::string getGpioLineName();
};
