cmake_minimum_required(VERSION 3.5)

add_library(inheritance SHARED library.cpp Base.cpp BaseWrap.cpp)

build_python_target(inheritance)