
cmake_minimum_required(VERSION 2.8)
# Minimal of version of CMake you need to begin the build

project(HelloWorldProject)

message(INFO ${HelloWorldProject_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${HelloWorldProject_SOURCE_DIR}/bin)
# Name of the project

add_executable(HelloWorldProjectMain main.cpp) 
# Create executable with sources

