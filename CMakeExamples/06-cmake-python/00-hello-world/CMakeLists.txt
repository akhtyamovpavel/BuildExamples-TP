cmake_minimum_required(VERSION 3.5)

add_library(hello_ext SHARED example.cpp example.cpp wrapper.cpp ../01-classes/World.cpp ../01-classes/World.h ../01-classes/library.cpp)
build_python_target(hello_ext)
