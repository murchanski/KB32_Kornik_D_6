cmake_minimum_required(VERSION 3.26)
project(Transfer_thread_param C)

set(CMAKE_C_STANDARD 11)

add_executable(Transfer_thread_param main.c
        thread_utils.h
        thread_utils.c)
