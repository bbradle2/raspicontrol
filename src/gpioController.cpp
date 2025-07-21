#include <gpioController.hpp>
#include <thread>
#include <iostream>

using namespace std;

gpioController::gpioController()
{   
    _chip.open(CHIP_NAME);

    _gpios.emplace("gpio23", new gpioObject(_chip, 23, 0, GPIOD_LINE_REQUEST_DIRECTION_OUTPUT));
    _gpios.emplace("gpio24", new gpioObject(_chip, 24, 0, GPIOD_LINE_REQUEST_DIRECTION_OUTPUT));

}

gpioController::~gpioController()
{
    for (auto gpio : _gpios)
    {
        if (gpio.second != nullptr) 
        {
            std::cout << "Deleting " << gpio.first << std::endl;
            delete gpio.second;
            gpio.second = nullptr;
        }
    }
    _gpios.clear();
    
}

std::map<std::string, gpioObject *> gpioController::getGpioObjects()
{
    return _gpios;
}
