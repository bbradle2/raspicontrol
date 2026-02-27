#include <raspConfig.hpp>

int main(int argc, char *argv[])
{
    logger::log("Begin");

    try
    {
        startProgram();
        printProgramInformation();
        printProgramArgs(argc, argv);
        runProgram(argc, argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "," << utils::getDateTimeLocal() << ENDLINE;
    }
    
    stopProgram();

    logger::log("End");
    return 0;
}

void printProgramInformation()
{
    logger::log("Begin");

    char character = '-';
    int times = 55;

    std::cout << std::string(times, character) << ENDLINE;
    std::cout << "Project:     " << PROJECT_NAME << ENDLINE;
    std::cout << "Description: " << PROJECT_DESCRIPTION << ENDLINE;
    std::cout << "Version:     " << PROJECT_VERSION << ENDLINE;
    std::cout << "Build Date:  " << __DATE__ << ENDLINE;
    std::cout << "Build Time:  " << __TIME__ << ENDLINE;
    std::cout << std::string(times, character) << ENDLINE;

    logger::log("End");
}

void startProgram()
{
    logger::log("Begin");

    std::cout << PROJECT_NAME << " Started: " << utils::getDateTimeLocal() << ENDLINE;

    logger::log("End");
}

void printProgramArgs(int argc, char *argv[])
{
    logger::log("Begin");

    std::cout << "argc: " << argc << ENDLINE;
    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << ENDLINE;
    }

    logger::log("End");
}

int runProgram(int argc, char *argv[])
{
    logger::log("Begin");
    // Do whatever
    // gpioController gpioCtl;

    // gpioCtl.getGpios()[GPIO23]->setGpioValue(1);
    // gpioCtl.getGpios()[GPIO24]->setGpioValue(1);
    // //std::this_thread::sleep_for(1000ms);
    // gpioCtl.getGpios()[GPIO23]->setGpioValue(0);
    // gpioCtl.getGpios()[GPIO24]->setGpioValue(0);
    logger::log("End");
    return 0;
}

int stopProgram()
{
    logger::log("Begin");

    std::cout << PROJECT_NAME << " Stopped: " << utils::getDateTimeLocal() << std::endl;

    logger::log("End");
    return 0;
}