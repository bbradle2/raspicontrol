#ifndef GPIOCONTROLLER_H
#define GPIOCONTROLLER_H

#include <string>
#include <thread>
#include <iostream>
#include <map>
#include <memory>
#include <gpiod.hpp>
#include <gpioObject.hpp>
#include <utils.hpp>

class gpioController
{

private:
    gpiod::chip _chip;
    std::map<std::string,  gpioObject*> _gpios;

public:
    gpioController()
    {
        utils::log("Begin");
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

        _chip.open(CHIP_NAME);

        _gpios.emplace(GPIO23, new gpioObject{_chip, PIN23, GPIOD_LINE_REQUEST_DIRECTION_OUTPUT});
        _gpios.emplace(GPIO24, new gpioObject{_chip, PIN24, GPIOD_LINE_REQUEST_DIRECTION_OUTPUT});
        utils::log("End");
    }

    ~gpioController()
    {
        utils::log("Begin");

        for (auto gpio : _gpios)
        {
            if (gpio.second != nullptr)
            {
                delete gpio.second;
                gpio.second = nullptr;
            }
        }

        _gpios.clear();

        utils::log("End");
    }

    std::map<std::string, gpioObject *> getGpios()
    {
        utils::log("Begin");
        if (_gpios.size() < 1)
            throw std::length_error("No Gpios allocated.");

        utils::log("End");
        return _gpios;
    }
};

#endif