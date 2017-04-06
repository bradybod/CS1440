cmake_minimum_required(VERSION 3.6)
project(HW6_Generics)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp KeyValue.hpp Dictionary.hpp)
add_executable(HW6_Generics ${SOURCE_FILES} KeyValue.hpp)