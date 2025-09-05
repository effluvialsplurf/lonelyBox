# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(lonelyBox CXX)

# find the raylib package when building
find_package(raylib REQUIRED)

# executable target, builds from this file out
add_executable(lonelyBox src/main.cpp)

# link the executable with the raylib library
target_link_libraries(lonelyBox PRIVATE raylib)
