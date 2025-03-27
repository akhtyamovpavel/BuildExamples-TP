cmake_minimum_required(VERSION 3.10)
# Minimal of version of CMake you need to begin the build

#set(CMAKE_C_COMPILER mpicc)
#set(CMAKE_CXX_COMPILER mpic++)
project(HelloWorldProject)

message(INFO ${HelloWorldProject_SOURCE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${HelloWorldProject_SOURCE_DIR}/bin)
# Name of the project

add_executable(HelloWorldProjectMain main.cpp) 
# Create executable with sources

