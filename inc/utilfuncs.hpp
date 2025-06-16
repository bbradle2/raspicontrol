#pragma once

#include <string>
#include <chrono>
#include <algorithm>
#include <iostream>

extern volatile int shutdown;
// function declarations
void shutdownThreadFunction();
std::string getDateTimeLocal();