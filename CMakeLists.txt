cmake_minimum_required(VERSION 3.0.0)
project(AP1-1 VERSION 0.1.0)

set(C_STANDART C99)
add_library(AP1-1 STATIC ErrorCode.h ErrorCode.c Matrix.h Matrix.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
