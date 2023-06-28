cmake_minimum_required(VERSION 3.25)
project(MathCompiler C)

set(CMAKE_C_STANDARD 23)

add_executable(MathCompiler main.c compiler.h execute.h queue.h compiler.c queue.c execute.c)
