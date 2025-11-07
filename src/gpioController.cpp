#include <gpioController.hpp>

using namespace std;

gpioController::gpioController()
{
    // auto lineTest = gpiod::find_line("GPIO24");
    // std::cout << lineTest.name() << "  " << lineTest.offset() << std::endl;
    // for (const auto &chip : gpiod::make_chip_iter())
    // {
    //     std::cout << chip.name() << " (" << chip.label() << ") " << "(" << chip.num_lines() << ")" << std::endl;

    //     for(auto line : chip.get_all_lines())
    //     {
    //         std::cout << "   " << line.name() << "  " << line.offset()  << std::endl;
    //     }
    // }
    // std::cout << std::endl;

    _chip.open(RaspberryPiDefines::CHIP_NAME);

    _gpios.emplace(RaspberryPiDefines::GPIO23, new gpioObject{_chip, RaspberryPiDefines::PIN23, GPIOD_LINE_REQUEST_DIRECTION_OUTPUT});
    _gpios.emplace(RaspberryPiDefines::GPIO24, new gpioObject{_chip, RaspberryPiDefines::PIN24, GPIOD_LINE_REQUEST_DIRECTION_OUTPUT});
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

std::map<std::string, gpioObject *> gpioController::getGpios()
{
    if (_gpios.size() < 1)
        throw std::length_error("No Gpios allocated.");

    return _gpios;
}
