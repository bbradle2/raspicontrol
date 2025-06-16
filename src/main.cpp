#include <gpiod.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <filesystem>
#include <iomanip>
#include <thread>
#include <datastructures.hpp>

// function declarations
void shutdownTask();
std::string getdatetimelocal();

//global variables
volatile int shutdown = 0;
gpiod::chip chip("gpiochip0");
gpiod::line line;
std::jthread t = std::jthread(shutdownTask);

int main()
{
    using namespace std::literals;

    try
    {
        Defer d = defer(
            []()
            {
                line.set_value(0);
                line.release();
                t.join();

                std::cout << "Program Stopped : " << getdatetimelocal() << std::endl;
            });

        std::cout << "Program Starting : " << getdatetimelocal() << std::endl;

        line = chip.get_line(23); // GPIO 23
        line.request({ "led-toggle", gpiod::line_request::DIRECTION_OUTPUT }, 0);

        while (shutdown == 0)
        {           
            line.set_value(1);
            std::this_thread::sleep_for(1s);
            line.set_value(0);
            std::this_thread::sleep_for(1s);
        }
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << getdatetimelocal() << std::endl;
        return 1;
    }

    return 0;
}

std::string getdatetimelocal()
{
    std::time_t now = std::time(nullptr);
    std::tm *local_time = std::localtime(&now);
    std::string asc = std::asctime(local_time);

    if (!asc.empty())
        asc.pop_back();

    return asc;
}

void shutdownTask()
{
    std::string command;

    while (std::cin >> command)
    {
        if (command == "quit")
        {
            shutdown = 1;
            std::cout << "Shutting Down Now : " << getdatetimelocal() << std::endl;
            break;
        }

        std::cin.clear();
    }
}