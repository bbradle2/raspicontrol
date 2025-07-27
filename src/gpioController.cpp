#include <gpioController.hpp>
#include <thread>
#include <iostream>
#include <gpioDefines.hpp>

using namespace std;

gpioController::gpioController()
{
    
    _chip.open(CHIP_NAME);
    _gpios.emplace(GPIO23, new gpioObject(_chip, PIN23, 0, GPIOD_LINE_REQUEST_DIRECTION_OUTPUT));
    _gpios.emplace(GPIO24, new gpioObject(_chip, PIN24, 0, GPIOD_LINE_REQUEST_DIRECTION_OUTPUT));
}

gpioController::~gpioController()
{
    for (auto gpio : _gpios)
    {
        if (gpio.second != nullptr) 
        {
            delete gpio.second;
            gpio.second = nullptr;
        }
    }
    _gpios.clear();
    
}

std::map<std::string, gpioObject*> gpioController::getGpioObjects()
{
     return _gpios;
}
