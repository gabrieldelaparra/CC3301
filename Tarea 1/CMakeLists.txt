cmake_minimum_required(VERSION 3.4)
project(Tarea_1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.c lifegame.c lifegame.h)
add_executable(Tarea_1 ${SOURCE_FILES})