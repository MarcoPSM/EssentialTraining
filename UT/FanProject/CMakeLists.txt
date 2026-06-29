cmake_minimum_required(VERSION 3.10)
project(FanProject)

set(CMAKE_CXX_STANDARD 11)

find_package(CppUTest REQUIRED)

add_executable(runTests main.cpp)
