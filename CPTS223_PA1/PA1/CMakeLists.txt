cmake_minimum_required(VERSION 3.16)
project(PA1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(PA1 main.cpp endFunctions.cpp endFunctions.hpp inFunctions.cpp inFunctions.hpp root.cpp root.hpp template_classes.hpp)
configure_file(commands.csv ${CMAKE_CURRENT_BINARY_DIR}/commands.csv COPYONLY)
configure_file(profiles.csv ${CMAKE_CURRENT_BINARY_DIR}/profiles.csv COPYONLY)
