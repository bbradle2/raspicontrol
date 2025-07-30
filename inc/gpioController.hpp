#pragma once

#include <string>
#include <gpiod.hpp>
#include <gpioObject.hpp>
#include <thread>
#include <iostream>
#include <raspberryPiDefines.hpp>
#include <map>
#include <memory>

class gpioController
{

private:
    gpiod::chip _chip;
    std::map<std::string,  gpioObject*> _gpios;

public:
    gpioController();
    ~gpioController();
    std::map<std::string, gpioObject*> getGpioObjects();
};
