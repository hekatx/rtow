cmake_minimum_required(VERSION 3.15)

project(rtow)

set($ENV{CMAKE_EXPORT_COMPILE_COMMANDS}, 1)

set(sources
    src/core/ppm_image.cpp
)

set(exe_sources
    src/main.cpp
		${sources}
)

set(headers
    includes/math.hpp
    includes/ppm_image.hpp
)

set(CMAKE_BUILD_TYPE "Debug")

message(STATUS "Started CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

include_directories(${CMAKE_SOURCE_DIR}/includes)

add_executable(rtow ${exe_sources} ${headers})
