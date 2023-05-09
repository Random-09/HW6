cmake_minimum_required(VERSION 3.24)
project(task1 C)

set(CMAKE_C_STANDARD 11)

add_executable(task1 main.c source/hash_table.c include/hash_table.h)
