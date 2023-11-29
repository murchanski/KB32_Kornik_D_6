cmake_minimum_required(VERSION 3.26)
project(Create_thread C)

set(CMAKE_C_STANDARD 11)

add_executable(Create_thread main.c
        thread.h
        thread.c)
