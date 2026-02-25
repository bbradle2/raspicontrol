#include <main.hpp>

int main(int argc, char *argv[])
{
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

    return stopProgram();
}

void printProgramInformation()
{
    utils::log("Begin");

    char character = '-';
    int times = 55;

    std::cout << std::string(times, character) << ENDLINE;
    std::cout << "Project:     " << PROJECT_NAME << ENDLINE;
    std::cout << "Description: " << PROJECT_DESCRIPTION << ENDLINE;
    std::cout << "Version:     " << PROJECT_VERSION << ENDLINE;
    std::cout << "Build Date:  " << __DATE__ << ENDLINE;
    std::cout << "Build Time:  " << __TIME__ << ENDLINE;
    std::cout << std::string(times, character) << ENDLINE;

    utils::log("End");
    std::cout << ENDLINE;
}

void startProgram()
{
    utils::log("Begin");
    std::cout << PROJECT_NAME << " Started: " << utils::getDateTimeLocal() << ENDLINE;
    utils::log("End");
    std::cout << ENDLINE;
}

void printProgramArgs(int argc, char *argv[])
{
    utils::log("Begin");
    std::cout << "argc: " << argc << ENDLINE;
    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << ENDLINE;
    }

    utils::log("End");
    std::cout << ENDLINE;
}

int runProgram(int argc, char *argv[])
{
    utils::log("Begin");
    // Do whatever
    gpioController gpioCtl;
    gpioCtl.getGpios()[GPIO23]->setGpioValue(1);
    gpioCtl.getGpios()[GPIO24]->setGpioValue(1);

    gpioCtl.getGpios()[GPIO23]->setGpioValue(0);
    gpioCtl.getGpios()[GPIO24]->setGpioValue(0);

    utils::log("End");
    std::cout << ENDLINE;
    return 0;
}

int stopProgram()
{
    utils::log("Begin");
    std::cout << PROJECT_NAME << " Stopped: " << utils::getDateTimeLocal() << std::endl;
    utils::log("End");
    return 0;
}