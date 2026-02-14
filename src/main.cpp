#include <main.hpp>


int main(int argc, char *argv[])
{
    try
    {
        startProgram(argc, argv);      
    }
    catch (const Poco::Exception &e)
    {
        std::cerr << "Error: " << e.displayText() << " " << UtilFuncs::getDateTimeLocal() << ENDLINE;
    }
    catch (const boost::exception &e)
    {
        std::cerr << "Error: " << boost::diagnostic_information(e) << UtilFuncs::getDateTimeLocal() << ENDLINE;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << " " << UtilFuncs::getDateTimeLocal() << ENDLINE;
    }

    
    return stopProgram();
}

void startProgram(int argc, char *argv[])
{

    std::cout << "Build Date: " << __DATE__ << ENDLINE;
    std::cout << "Build Time: " << __TIME__ << ENDLINE;
    std::cout << ENDLINE;

    std::cout << "Program Started: " << UtilFuncs::getDateTimeLocal() << ENDLINE;
    std::cout << "argc: " << argc << ENDLINE;
    for (int i = 0; i < argc; i++)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << ENDLINE;
    }

    std::cout << ENDLINE;
}

int stopProgram()
{
    std::cout << "Program Stopped: " << UtilFuncs::getDateTimeLocal() << ENDLINE;
    return 0;
}