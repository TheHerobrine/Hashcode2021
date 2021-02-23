cmake_minimum_required(VERSION 3.17)

set(Project Hashcode)
set(CMAKE_CXX_STANDARD 20)

project(${Project})

add_subdirectory(googletest)
add_subdirectory(src)
add_subdirectory(test)