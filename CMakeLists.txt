cmake_minimum_required(VERSION 4.0.3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

file(GLOB SOURCES_CPP CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB SOURCES_C CONFIGURE_DEPENDS "src/*.c")
set(SOURCES_FILES ${SOURCES_CPP} ${SOURCES_C})

project(raspicontrol VERSION 1.5)

add_executable(${PROJECT_NAME} ${SOURCES_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE gpiodcxx)


