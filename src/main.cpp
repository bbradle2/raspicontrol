#include <raspConfig.hpp>

static void printProgramInformation(int argc, char *argv[]);
static int runProgram(int argc, char *argv[]);

static int runProgram(int argc, char *argv[])
{
    utils::log("Begin");
    // Do whatever
    // gpioController gpioCtl;

    // gpioCtl.getGpios()[GPIO23]->setGpioValue(1);
    // gpioCtl.getGpios()[GPIO24]->setGpioValue(1);
    // std::this_thread::sleep_for(1000ms);
    // gpioCtl.getGpios()[GPIO23]->setGpioValue(0);
    // gpioCtl.getGpios()[GPIO24]->setGpioValue(0);
    utils::log("End");
    return 0;
}


int main(int argc, char *argv[])
{
    utils::log(std::string(PROJECT_NAME) + " Started:", WARNING);
    utils::log("Begin");
   
    int retCode = 0;

    try
    {
        printProgramInformation(argc, argv);
        retCode = runProgram(argc, argv);
    }
    catch (const std::exception &e)
    {

        std::cerr << "Error: " << e.what() << "," << utils::dateTimeLocal() << ENDLINE;
        retCode = -1;
    }

    utils::log("End");
    utils::log(std::string(PROJECT_NAME) + " Stopped:", WARNING);
    return retCode;
}

static void printProgramInformation(int argc, char *argv[])
{
    utils::log("Begin");

    char startAndEnd = '-';
    char divider = '#';
    int times = 100;

    utils::printInfo(std::string(times, startAndEnd));
    utils::printInfo("Project:     " + std::string(PROJECT_NAME));
    utils::printInfo("Description: " + std::string(PROJECT_DESCRIPTION));
    utils::printInfo("Version:     " + std::string(PROJECT_VERSION));
    utils::printInfo("Build Date:  " + std::string(__DATE__));
    utils::printInfo("Build Time:  " + std::string(__TIME__));
    utils::printInfo(std::string(times, divider));

    utils::printInfo("argc: " + std::to_string(argc));
    for (int i = 0; i < argc; i++)
    {
        utils::printInfo("argv[" + std::to_string(i) + "]: " + argv[i]);
    }

    utils::printInfo(std::string(times, startAndEnd));
    utils::log("End");
}
