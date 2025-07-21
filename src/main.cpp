#include <main.hpp>

int main(int argc, char **argv)
{
    try
    {
        std::cout << "Program Started: " << utilFuncs::getDateTimeLocal() << std::endl;
        std::cout << "Build Date: " << __DATE__ << std::endl;
        std::cout << "Build Time: " << __TIME__ << std::endl;

        std::cout << "argc: " << argc << std::endl;

        for (int i = 0; i < argc; i++)
        {
            std::cout << "argv[" << i << "]:" << argv[i] << std::endl;
        }

        gpioController gpioCtl;
        auto gpios = gpioCtl.getGpioObjects();
        gpios["gpio23"]->setGpioValue(1);
        gpios["gpio24"]->setGpioValue(1);
        std::this_thread::sleep_for(1000ms);
        gpios["gpio23"]->setGpioValue(0);
        gpios["gpio24"]->setGpioValue(0);

    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << " " << utilFuncs::getDateTimeLocal() << std::endl;
        goto programStop;
    }

programStop:   
    std::cout << "Program Stopped: " << utilFuncs::getDateTimeLocal() << std::endl;
    return 0;


}