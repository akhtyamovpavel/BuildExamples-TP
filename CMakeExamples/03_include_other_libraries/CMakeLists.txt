cmake_minimum_required(VERSION 3.1)

project(ListDirectory)

set(CMAKE_CXX_STANDARD 11)

find_package(Boost COMPONENTS filesystem system REQUIRED)

include_directories(include)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(ListDirectory main.cpp)

add_subdirectory(src)
target_link_libraries(ListDirectory ${Boost_LIBRARIES} ListDir)
