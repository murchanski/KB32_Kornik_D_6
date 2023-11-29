cmake_minimum_required(VERSION 3.26)
project(Waiting_thread C)

set(CMAKE_C_STANDARD 11)

add_executable(Waiting_thread main.c
        child_thread.c
        child_thread.h)
