cmake_minimum_required(VERSION 4.0.3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(PRIVATE inc)

project(raspcontrol VERSION 1.5)

add_executable(raspcontrol src/main.cpp)
target_link_libraries(raspcontrol PRIVATE gpiodcxx)


