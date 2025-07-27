#include <main.hpp>
#include <valgrind/valgrind.h>

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
            std::cout << "argv[" << i << "]:" << argv[i] << std::endl;
        }
        std::cout << std::endl;

         gpioController gpioCtl;
         
          gpioCtl.getGpioObjects()["gpio23"]->setGpioValue(1);
          gpioCtl.getGpioObjects()["gpio24"]->setGpioValue(1);
          std::this_thread::sleep_for(1000ms);
          gpioCtl.getGpioObjects()["gpio23"]->setGpioValue(0);
          gpioCtl.getGpioObjects()["gpio24"]->setGpioValue(0);
    }
    catch (const Poco::Exception &e)
    {
        std::cerr << "Error: " << e.displayText() << " " << utilFuncs::getDateTimeLocal() << std::endl;
    }
    catch (boost::exception &e)
    {
        std::cerr << "Error: " << boost::diagnostic_information(e) << std::endl;
    }
    catch (const exception &e)
    {
        std::cerr << "Error: " << e.what() << " " << utilFuncs::getDateTimeLocal() << std::endl;
    }

    std::cout << "Program Stopped: " << utilFuncs::getDateTimeLocal() << std::endl;
    return 0;
}
