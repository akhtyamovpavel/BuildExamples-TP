cmake_minimum_required(VERSION 3.10)
project(ListDir)


add_library(ListDir SHARED ListDir.cpp)

target_link_libraries(ListDir Boost::filesystem)
target_include_directories(ListDir PRIVATE ${ListDirectory_SOURCE_DIR}/include)
target_include_directories(ListDir PRIVATE ${Boost_INCLUDE_DIRS})
target_link_directories(ListDir PRIVATE ${Boost_LIBRARY_DIRS})

