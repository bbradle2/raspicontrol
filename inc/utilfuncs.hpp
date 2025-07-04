#pragma once

#include <string>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <atomic>

extern volatile std::atomic<bool> shutdownFlag;
class utilfuncs 
{
    // function declarations
    public:
        static void commandThreadFunction();
        static std::string getDateTimeLocal();
};