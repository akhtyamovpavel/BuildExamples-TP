cmake_minimum_required(VERSION 3.5)

add_library(classes_simple SHARED World.cpp library.cpp)

build_python_target(classes_simple)