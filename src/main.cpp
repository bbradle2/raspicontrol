#include <main.hpp>

int main(int argc, char **argv)
{
    try
    {
        std::cout << "Build Date: " << __DATE__ << ENDLINE;
        std::cout << "Build Time: " << __TIME__ << ENDLINE;
        std::cout << ENDLINE;
      
        std::cout << "Program Started: " << myUtilFuncs::getDateTimeLocal() << ENDLINE;

        std::cout << "argc: " << argc << ENDLINE;
        for (int i = 0; i < argc; i++)
        {
            std::cout << "argv[" << i << "]: " << argv[i] << ENDLINE;
        }

        std::cout  << ENDLINE;

    }
    catch (const Poco::Exception &e)
    {
        std::cerr << "Error: " << e.displayText() << " " << myUtilFuncs::getDateTimeLocal() << ENDLINE;
    }
    catch (const boost::exception &e)
    {
        std::cerr << "Error: " << boost::diagnostic_information(e) << myUtilFuncs::getDateTimeLocal() << ENDLINE;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << " " << myUtilFuncs::getDateTimeLocal() << ENDLINE;
    }

    std::cout << "Program Stopped: " << myUtilFuncs::getDateTimeLocal() << ENDLINE;

    return 0;
}