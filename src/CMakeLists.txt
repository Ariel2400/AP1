cmake_minimum_required(VERSION 3.0.0)
project(AP1-1 VERSION 0.1.0)

set(C_STANDART C99)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
add_library(matrix SHARED ErrorCode.c Matrix.c)
add_compile_options(-Wall -Wextra -pedantic -Werror)
<<<<<<< HEAD:CMakeLists.txt
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
=======
add_library(AP1-1 SHARED ErrorCode.h ErrorCode.c Matrix.h Matrix.c)
=======
add_library(AP1-1 SHARED  ErrorCode.c Matrix.c)
>>>>>>> Edited CMakeLists to exclude header files
=======
add_library(matrix SHARED  ErrorCode.c Matrix.c)
>>>>>>> Changed destination library to 'libmatrix.so'
=======
add_library(matrix SHARED ErrorCode.c Matrix.c)
>>>>>>> deleted unneccesary space
add_compile_options(-Wall -Wextra -pedantic -Werror)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
>>>>>>> moved all source code to src folder
=======
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
>>>>>>> added src directory:src/CMakeLists.txt
=======
add_library(matrix SHARED ErrorCode.c Matrix.c)
add_compile_options(-Wall -Wextra -pedantic -Werror)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
>>>>>>> 2c44f44094a0db5154e0ed8bef6fadc1554dfc02
