cmake_minimum_required(VERSION 3.1)
project(ListDir)


add_library(ListDir SHARED ListDir.cpp)

target_link_libraries(ListDir Boost::filesystem)

