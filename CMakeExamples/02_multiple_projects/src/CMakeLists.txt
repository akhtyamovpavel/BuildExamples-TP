cmake_minimum_required(VERSION 2.8)

project(FirstClass)

set(SOURCE_LIB FirstClass.cpp)

add_library(FirstClass SHARED ${SOURCE_LIB})
