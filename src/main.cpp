#include <main.hpp>

int main(int argc, char **argv)
{
    try
    {
        std::cout << "Program Started: " << utilFuncs::getDateTimeLocal() << std::endl;
        
        std::cout << "Build Date: " << __DATE__ << std::endl;
        std::cout << "Build Time: " << __TIME__ << std::endl;
        std::cout << std::endl;

        std::cout << "argc: " << argc << std::endl;
        for (int i = 0; i < argc; i++)
        {
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
        }
        std::cout << std::endl;
        
        gpioController gpioCtl;
        std::cout << "Gpio 23 Value:" << gpioCtl.getGpios()[GPIO23]->setGpioValue(1) << std::endl;
        std::this_thread::sleep_for(1000ms); // delay for 1000 milliseconds.
        std::cout << "Gpio 23 Value:" << gpioCtl.getGpios()[GPIO23]->setGpioValue(0) << std::endl;
    }
    catch (const Poco::Exception &e)
    {
        std::cerr << "Error: " << e.displayText() << " " << utilFuncs::getDateTimeLocal() << std::endl;
    }
    catch (boost::exception &e)
    {
        std::cerr << "Error: " << boost::diagnostic_information(e) << utilFuncs::getDateTimeLocal() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << " " << utilFuncs::getDateTimeLocal() << std::endl;
    }

    std::cout << "Program Stopped: " << utilFuncs::getDateTimeLocal() << std::endl;
    return 0;
}