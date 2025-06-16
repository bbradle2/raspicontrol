
#include <string>

volatile int shutdown = 0;
gpiod::chip chip("gpiochip0");
gpiod::line line;

// function declarations
void shutdownTask();
std::string getdatetimelocal();

