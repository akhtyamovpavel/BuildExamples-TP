cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0074 NEW)
project(IncludeLibrary)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" ${CMAKE_SOURCE_DIR}/cmake)

find_package(FC REQUIRED)

message(INFO ${FC_LIBRARY_DIR})

add_executable(main main.cpp)
target_include_directories(main PRIVATE ${FC_INCLUDE_DIR})
target_link_directories(main PRIVATE ${FC_LIBRARY_DIR})
target_link_libraries(main ${FC_LIBRARIES})

