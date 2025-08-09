#include <gpioObject.hpp>

gpioObject::gpioObject(gpiod::chip chip, int gpioNumber, int direction = GPIOD_LINE_REQUEST_DIRECTION_OUTPUT)
{
    _gpioNumber = gpioNumber;
          
    _line = chip.get_line(_gpioNumber);
    _direction = direction;

    if(!_line.is_requested()) 
    {
        _lineName = _line.name();
        _line.request({_lineName, _direction, 0}, 0);
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

int gpioObject::setGpioValue(int gpioValue)
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

void gpioObject::setGpioDirection(int direction)
{
    _direction = direction;
}

int gpioObject::getGpioDirection()
{
    return _direction;
}

std::string gpioObject::getGpioLineName()
{
    return _lineName;
}
