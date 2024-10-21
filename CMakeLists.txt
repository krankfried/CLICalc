cmake_minimum_required(VERSION 3.29)
project(CLICalc)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(CLICalc main.cpp
        calculator.cpp
        calculator.h)
