cmake_minimum_required(VERSION 2.8)

project(src)

set(SOURCE_LIB FirstClass.cpp)

add_library(src SHARED ${SOURCE_LIB})
