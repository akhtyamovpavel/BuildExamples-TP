cmake_minimum_required(VERSION 3.1)
project(ListDir)

find_package(Boost COMPONENTS filesystem system REQUIRED)


add_library(ListDir ListDir.cpp)

target_link_libraries(ListDir ${BOOST_LIBRARIES})
