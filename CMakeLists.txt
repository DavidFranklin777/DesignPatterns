cmake_minimum_required(VERSION 3.5)

project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DesignPatterns main.cpp)
set(INCLUDE_DIRECTORIES $CMAKE_CURRENT_DIR/Factory.h)
#include_directories($CMAKE_CURRENT_DIR/Factory.h)
include_directories($INCLUDE_DIRECTORIES)
