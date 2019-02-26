cmake_minimum_required(VERSION 2.8)

project(FirstClassAsLibrary)
set(MAIN_SOURCE main.cpp)
include_directories(include)


add_executable(FirstClassAsLibrary ${MAIN_SOURCE})
add_subdirectory(src)
target_link_libraries(FirstClassAsLibrary FirstClass)
