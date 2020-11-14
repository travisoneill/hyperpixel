cmake_minimum_required(VERSION 3.5.1)
project(hyperpixel)

include_directories(libhyperpixel, cpp-httplib-0.7.14)

set(SOURCES main.cpp libhyperpixel/utils.cpp libhyperpixel/server.cpp)

add_executable(main ${SOURCES})
target_compile_options (main PRIVATE -std=c++17)

set (CMAKE_CXX_STANDARD 17)
