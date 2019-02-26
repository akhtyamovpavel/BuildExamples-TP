cmake_minimum_required(VERSION 2.8)

project(Configurator)

set(Configurator_VERSION_MAJOR 1)
set(Configurator_VERSION_MINOR 0)

configure_file(${PROJECT_SOURCE_DIR}/Config.h.in ${PROJECT_SOURCE_DIR}/Config.h)


set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR})
add_executable(Configurator ${PROJECT_SOURCE_DIR}/Config.cpp)