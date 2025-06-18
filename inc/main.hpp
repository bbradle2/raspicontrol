#pragma once

#include <string>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <filesystem>
#include <iomanip>
#include <thread>
#include <gpiod.hpp>

std::atomic<bool> shutdownFlag(0);
gpiod::chip chip("gpiochip0");
gpiod::line line;



