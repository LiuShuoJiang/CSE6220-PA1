cmake_minimum_required(VERSION 3.22)
project(PA1)

find_package(MPI REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES main.cpp)

add_executable(pi_calc ${SOURCE_FILES})

target_link_libraries(pi_calc PUBLIC MPI::MPI_CXX)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(pi_calc PRIVATE -Wall -Wextra -pedantic -O3)
endif()
