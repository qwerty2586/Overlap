cmake_minimum_required(VERSION 3.3)
project(Overlap)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pedantic -ansi")

set(SOURCE_FILES main.c node.c overlap.c transmitter.c intstack.h intstack.c errors.h errors.c)
add_executable(Overlap ${SOURCE_FILES})