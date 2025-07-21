#pragma once
#include <string>
#include <gpiod.hpp>
#include <gpioObject.hpp>
#include <map>

#define CHIP_NAME "gpiochip0"

class gpioController
{

private:
    gpiod::chip _chip;
    std::map<std::string, gpioObject *> _gpios;

public:
    gpioController();
    ~gpioController();
    std::map<std::string, gpioObject *> getGpioObjects();
};
