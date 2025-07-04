#include <main.hpp>
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <uuid/uuid.h>
#include <cstring>
#include <mutex>

#include <defer.hpp>
#include <utilfuncs.hpp>

#define GPIO_23 23

using namespace std::literals;

int main()
{
    try
    {
        std::cout << "Program Starting: " << utilfuncs::getDateTimeLocal() << std::endl;
        std::cout << "Build Date: " << __DATE__ << std::endl;
        std::cout << "Build Time: " << __TIME__ << std::endl;
        
        // uuid_t uuid;
        // char cuuid[37] = {};

        // uuid_generate_random(uuid);
        // uuid_unparse_upper(uuid, cuuid);

        // std::cout << cuuid << std::endl;

        // goto exit;

        //shutdownFlag.store(false);
        //static std::jthread shutdownThread = std::jthread(utilfuncs::commandThreadFunction);

         Defer d = defer(
                         []()
                         {
                             //shutdownThread.request_stop();
                             //shutdownThread.join();
                             line.set_value(0);
                             line.release();
                             std::cout << "Program Stopped: " << utilfuncs::getDateTimeLocal() << std::endl;
                         });

        line = chip.get_line(GPIO_23); // GPIO 23
        line.request({ 
                       "led-toggle", 
                       gpiod::line_request::DIRECTION_OUTPUT 
                     });

        //while (shutdownFlag.load() == false)
        //{
            line.set_value(0);
            std::this_thread::sleep_for(1000ms);
            line.set_value(1);
            std::this_thread::sleep_for(1000ms);
        //}
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << utilfuncs::getDateTimeLocal() << std::endl;
        return 1;
    }

exit:
    //std::cout << "Program Stopped: " << utilfuncs::getDateTimeLocal() << std::endl;
    return 0;


}