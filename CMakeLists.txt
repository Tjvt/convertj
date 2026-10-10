cmake_minimum_required(VERSION 4.3)
project(convertj C)

set(CMAKE_C_STANDARD 23)

add_executable(convertj main.c)
target_link_libraries(convertj m)
