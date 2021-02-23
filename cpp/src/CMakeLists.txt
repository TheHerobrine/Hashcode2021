cmake_minimum_required(VERSION 3.17)
project(hashcode)

set(CMAKE_CXX_STANDARD 20)
include_directories(../googletest/googletest/include)

add_executable(hashcode main.cpp)
