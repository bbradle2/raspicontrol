cmake_minimum_required(VERSION 4.0.3)
project(raspicontrol VERSION 1.5)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_C_COMPILER clang) #CMAKE_CXX_STANDARD has to = 20 to use clang
# set(CMAKE_CXX_COMPILER clang++)

file(GLOB SOURCES_CPP CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB SOURCES_C CONFIGURE_DEPENDS "src/*.c")
set(SOURCES_FILES ${SOURCES_CPP} ${SOURCES_C})

add_executable(${PROJECT_NAME} ${SOURCES_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(${PROJECT_NAME} LINK_PRIVATE gpiodcxx)
target_link_libraries(${PROJECT_NAME} LINK_PRIVATE uuid)
