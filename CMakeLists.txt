cmake_minimum_required(VERSION 3.6)
project(CommandCalculatorStarter)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        CommandCalculator.cpp
        CommandCalculator.h
        Operations.cpp
        Operations.h)

add_executable(CommandCalculatorStarter ${SOURCE_FILES})