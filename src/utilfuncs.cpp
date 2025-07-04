#include <utilfuncs.hpp>

std::string utilfuncs::getDateTimeLocal()
{
    std::time_t now = std::time(nullptr);
    std::tm *local_time = std::localtime(&now);
    std::string asc = std::asctime(local_time);
    asc.erase(std::remove_if(asc.begin(), asc.end(), [](char ch)
                                                     { 
                                                        return std::iscntrl(static_cast<unsigned char>(ch)); 
                                                     }),
             asc.end()
             );

    return asc;
}

void utilfuncs::commandThreadFunction()
{
    std::cout << "Start utilfuncs::commandThreadFunction: " << getDateTimeLocal() << std::endl;
    std::string command;

    while (std::cin >> command)
    {
        if (command == "quit")
        {
            shutdownFlag.store(true);
            break;
        }

        std::cin.clear();
    }

    std::cout << "End utilfuncs::commandThreadFunction: " << getDateTimeLocal() << std::endl;
}