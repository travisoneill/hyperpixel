cmake_minimum_required(VERSION 3.18.1)
project(hyperpixel CXX)

message(STATUS ${CMAKE_SYSTEM_NAME})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)

include_directories(libhyperpixel, cpp-httplib-0.7.14)

set(SOURCES main.cpp libhyperpixel/utils.cpp libhyperpixel/server.cpp)

add_executable(main ${SOURCES})
target_compile_options (main PRIVATE -std=c++17)
target_link_libraries( main ${CMAKE_THREAD_LIBS_INIT} )

set(CMAKE_CXX_STANDARD 17)
