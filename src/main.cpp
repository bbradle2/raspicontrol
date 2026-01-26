#include <main.hpp>

int main(int argc, char **argv)
{
    try
    {
        std::cout << "Build Date: " << __DATE__ << std::endl;
        std::cout << "Build Time: " << __TIME__ << std::endl;
        std::cout << std::endl;

        std::cout << "Program Started: " << utilFuncs::getDateTimeLocal() << std::endl;

        std::cout << "argc: " << argc << std::endl;
        for (int i = 0; i < argc; i++)
        {
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
        }
        std::cout << std::endl;

    }
    catch (const Poco::Exception &e)
    {
        std::cerr << "Error: " << e.displayText() << " " << utilFuncs::getDateTimeLocal() << std::endl;
    }
    catch (const boost::exception &e)
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