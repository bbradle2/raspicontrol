#include <utilfuncs.hpp>

std::string getDateTimeLocal()
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

void shutdownThreadFunction()
{
    std::string command;

    while (std::cin >> command)
    {
        if (command == "quit")
        {
            bool oldValue = shutdownFlag.exchange(true);

            if (oldValue == false)
            {
                std::cout << "Shutting Down Now: " << getDateTimeLocal() << std::endl;
                break;
            }
        }

        std::cin.clear();
    }
}