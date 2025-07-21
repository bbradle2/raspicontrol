#include <gpioObject.hpp>
#include <gpiod.hpp>
#include <iostream>

gpioObject::gpioObject(gpiod::chip chip, int gpioNumber, int gpioValue, int direction = GPIOD_LINE_REQUEST_DIRECTION_OUTPUT)
{
    _gpioNumber = gpioNumber;
    _gpioValue = gpioValue;
    _line = chip.get_line(_gpioNumber);
    _direction = direction;

    if(!_line.is_requested()) 
    {
        _line.request({"led-toggle",
                   _direction, 0}, 0);
    }

}

gpioObject::~gpioObject()
{
    _line.release();
}

int gpioObject::getGpioValue()
{
    _gpioValue = _line.get_value();
    return _gpioValue;
}

void gpioObject::setGpioValue(int gpioValue)
{
    if(_line.direction() == gpiod::line::DIRECTION_OUTPUT) 
    {
        _gpioValue = gpioValue;
        _line.set_value(_gpioValue);
    } 
    else 
    {
        _gpioValue = _line.get_value();
    }
}

void gpioObject::setGpioDirection(int direction)
{
    _direction = direction;
}

int gpioObject::getGpioDirection()
{
    return _direction;
}
