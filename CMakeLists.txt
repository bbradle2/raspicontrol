cmake_minimum_required(VERSION 4.1.0)

project(raspicontrol VERSION 1.5)
add_compile_definitions(RASP5) # Equivalent to #define RASP5

#enable_testing()
set(CMAKE_CTEST_ARGUMENTS "-V" )
include (CTest)

#set(CTEST_MEMORYCHECK_TYPE Valgrind)
#SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
#SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")
#add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
#find_package(Boost REQUIRED COMPONENTS charconv)
#find_package(SQLiteCpp REQUIRED)
#find_package(MySQL REQUIRED)
#ctest -T memcheck --test-dir build

#find_package(SQLite3 REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Poco CONFIG REQUIRED Foundation Net Util Crypto NetSSL Data DataSQLite DataMySQL DataPostgreSQL)

pkg_search_module(GLIB REQUIRED glib-2.0)
#find_package(SQLite3 REQUIRED)
#find_package(Poco REQUIRED MySQL::client)
#include_directories(${Poco_INCLUDE_DIRECTORIES})
#set(CMAKE_OBJC_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#enable_language(OBJCXX)

# set(CMAKE_C_COMPILER clang) #CMAKE_CXX_STANDARD has to = 20 to use clang
# set(CMAKE_CXX_COMPILER clang++)
#add_compile_options(-W -Wall -Werror)
  # For a general case, not recommended, to preserve exiting cache variable
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
#set(CMAKE_EXE_LINKER_FLAGS "-framework Cocoa -framework AppKit -framework CoreData -framework Foundation")

#include_directories(${MYSQL_INCLUDE_DIR})
#include_directories(${Boost_INCLUDE_DIRS})
file(GLOB SOURCES_CPP CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB SOURCES_C CONFIGURE_DEPENDS "src/*.c")
#file(GLOB SOURCES_OBJC CONFIGURE_DEPENDS "src/*.m")
set(SOURCES_FILES ${SOURCES_CPP} ${SOURCES_C})


add_executable(${PROJECT_NAME} ${SOURCES_FILES})
#file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/example.db")

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME} testarg )


add_test(NAME ${PROJECT_NAME}_memcheck
    COMMAND valgrind
      --error-exitcode=1
      --tool=memcheck
      --leak-check=full --track-origins=yes
      --errors-for-leak-kinds=definite
      --show-leak-kinds=definite
      --track-fds=yes
      $<TARGET_FILE:${PROJECT_NAME}>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )

add_test(NAME ${PROJECT_NAME}_helgrind
    COMMAND valgrind
      --error-exitcode=1
      --tool=helgrind
      --track-fds=yes
      $<TARGET_FILE:${PROJECT_NAME}>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME ${PROJECT_NAME}_cachegrind
    COMMAND valgrind
      --error-exitcode=1
      --tool=cachegrind
      --track-fds=yes
      $<TARGET_FILE:${PROJECT_NAME}>
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/inc)
target_include_directories(${PROJECT_NAME} PRIVATE ${GLIB_INCLUDE_DIRS})
#target_include_directories(${PROJECT_NAME} PRIVATE  /usr/lib/gcc/aarch64-linux-gnu/12/include)
#target_include_directories(${PROJECT_NAME} PRIVATE  /usr/include/GNUstep)

#target_link_libraries(${PROJECT_NAME} LINK_PRIVATE SQLite::SQLite3)

target_link_libraries(${PROJECT_NAME} LINK_PRIVATE Poco::Net Poco::Foundation Poco::Util Poco::Crypto Poco::NetSSL Poco::Data Poco::DataSQLite Poco::DataMySQL Poco::DataPostgreSQL)
target_link_libraries(${PROJECT_NAME} LINK_PRIVATE gpiodcxx)
target_link_libraries(${PROJECT_NAME} LINK_PRIVATE uuid)
target_link_libraries(${PROJECT_NAME} LINK_PRIVATE crypto++)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE ${GLIB_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} PRIVATE gnustep-base objc)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
#target_link_libraries(${PROJECT_NAME} LINK_PRIVATE mysqlcppconn)
#target_link_libraries(${PROJECT_NAME} ${Poco_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} SQLiteCpp)

    # function(print_all_variables)
    #     message(STATUS "CMake Variables:")
    #     get_cmake_property(_variableNames VARIABLES)
    #     list(SORT _variableNames)
    #     foreach (_variableName ${_variableNames})
    #         message(STATUS "${_variableName}=${${_variableName}}")
    #     endforeach()
    # endfunction()

    # print_all_variables()
