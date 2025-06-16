
#include <defer.hpp>
#include <utilfuncs.hpp>
#include <main.hpp>

int main()
{
    try
    {
        using namespace std::literals;
        static std::jthread shutdownThread = std::jthread(shutdownThreadFunction);

        auto concurrent = shutdownThread.hardware_concurrency();

        Defer d = defer(
            []()
            {
                line.set_value(0);
                line.release();
                shutdownThread.request_stop();
                shutdownThread.join();

                std::cout << "Program Stopped: " << getDateTimeLocal() << std::endl;
            });

        std::cout << "Build Date: " << __DATE__ << std::endl;
        std::cout << "Build Time: " << __TIME__ << std::endl;

        std::cout << "Program Starting: " << getDateTimeLocal() << std::endl;

        line = chip.get_line(23); // GPIO 23
        line.request({ 
                       "led-toggle", 
                       gpiod::line_request::DIRECTION_OUTPUT 
                     });

        while (shutdown == 0)
        {           
            line.set_value(1);
            std::this_thread::sleep_for(1000ms);
            line.set_value(0);
            std::this_thread::sleep_for(1000ms);
        }
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << getDateTimeLocal() << std::endl;
        return 1;
    }

    return 0;
}