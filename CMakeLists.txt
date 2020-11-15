cmake_minimum_required(VERSION 3.18.1)
project(hyperpixel CXX)

message(STATUS ${CMAKE_SYSTEM_NAME})

# gSLICr flags
set(CFLAGS_WARN "-Wall -Wextra -Wno-unused-parameter -Wno-strict-aliasing")
set(CMAKE_CXX_FLAGS "-fPIC -O3 -D_FORCE_INLINES -march=native ${CFLAGS_WARN} ${CMAKE_CXX_FLAGS}")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)

include_directories(libhyperpixel, cpp-httplib-0.7.14)

# gSLICr reqirements
find_package(CUDA REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(ORUtils)

set(GSLICR_LIB
gSLICr_Lib/engines/gSLICr_core_engine.h
gSLICr_Lib/engines/gSLICr_seg_engine.h
gSLICr_Lib/engines/gSLICr_seg_engine_GPU.h
gSLICr_Lib/engines/gSLICr_seg_engine_shared.h
gSLICr_Lib/engines/gSLICr_core_engine.cpp
gSLICr_Lib/engines/gSLICr_seg_engine.cpp
gSLICr_Lib/engines/gSLICr_seg_engine_GPU.cu
gSLICr_Lib/objects/gSLICr_settings.h
gSLICr_Lib/objects/gSLICr_spixel_info.h
gSLICr_Lib/gSLICr_defines.h
gSLICr_Lib/gSLICr.h
)

list(APPEND "-std=c++11 -ftree-vectorize")
SOURCE_GROUP(engines FILES ${GSLICR_LIB})

cuda_add_library(gSLICr_lib
			${GSLICR_LIB}
			NVTimer.h
			OPTIONS -gencode arch=compute_30,code=compute_30)
target_link_libraries(gSLICr_lib ${CUDA_LIBRARY})

set(SOURCES main.cpp libhyperpixel/utils.cpp libhyperpixel/server.cpp)

add_executable(main ${SOURCES})
target_compile_options(main PRIVATE -std=c++17)
target_link_libraries(main ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(main gSLICr_lib ${OpenCV_LIBS})

set(CMAKE_CXX_STANDARD 17)
