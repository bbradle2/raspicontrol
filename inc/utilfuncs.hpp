#pragma once

#include <string>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <atomic>

extern std::atomic<bool> shutdownFlag;
// function declarations
void shutdownThreadFunction();
std::string getDateTimeLocal();