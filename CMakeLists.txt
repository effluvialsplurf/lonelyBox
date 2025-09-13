# CMake version
cmake_minimum_required(VERSION 3.25)

# Project name and language
project(lonelyBox C)

set(CMAKE_C_STANDRD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.c)

# find the raylib package when building
find_package(raylib REQUIRED)

# executable target, builds from this file out
add_executable(${PROJECT_NAME} ${SRC_FILES})

# link the executable with the raylib library
target_link_libraries(${PROJECT_NAME} PRIVATE raylib m)
