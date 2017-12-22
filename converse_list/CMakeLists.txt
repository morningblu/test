cmake_minimum_required(VERSION 3.8)
project(converse_list)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.c
        makefile)

add_executable(converse_list ${SOURCE_FILES})