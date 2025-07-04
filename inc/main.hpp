#pragma once

#include <string>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <filesystem>
#include <iomanip>
#include <thread>
#include <gpiod.hpp>

volatile std::atomic<bool> shutdownFlag(false);
gpiod::chip chip("gpiochip0");
gpiod::line line;
