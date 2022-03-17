cmake_minimum_required(VERSION 3.5)

add_library(
    hello_ext SHARED 
    example.cpp
    wrapper.cpp
)
build_python_target(hello_ext)
