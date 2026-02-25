#ifndef GPIOOBJECT_H
#define GPIOOBJECT_H

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
    gpioObject(gpiod::chip chip, int gpioNumber, int direction = GPIOD_LINE_REQUEST_DIRECTION_OUTPUT)
    {
        _gpioNumber = gpioNumber;

        _line = chip.get_line(_gpioNumber);
        _direction = direction;

        if (!_line.is_requested())
        {
            _lineName = _line.name();
            _line.request({_lineName, _direction, 0}, 0);
        }
    }

    ~gpioObject()
    {
        _line.release();
    }

    int getGpioValue()
    {
        _gpioValue = _line.get_value();
        return _gpioValue;
    }

    int setGpioValue(int gpioValue)
    {
        if (gpioValue < 0 || gpioValue > 1)
            throw std::invalid_argument("gpioValue must be a 1 or a 0.");

        if (_line.direction() == gpiod::line::DIRECTION_OUTPUT)
        {
            _gpioValue = gpioValue;
            _line.set_value(_gpioValue);
        }
        else
        {
            _gpioValue = _line.get_value();
        }

        return _gpioValue;
    }

    void setGpioDirection(int direction)
    {
        _direction = direction;
    }

    int getGpioDirection()
    {
        return _direction;
    }

    std::string getGpioLineName()
    {
        return _lineName;
    }
};
#endif