cmake_minimum_required(VERSION 3.1)

project(ListDirectory)

set(CMAKE_CXX_STANDARD 11)

#set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_MULTITHREADED ON)

find_package(Boost COMPONENTS filesystem system REQUIRED)

include_directories(include)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(ListDirectory main.cpp)

add_subdirectory(src)

link_directories(${Boost_LIBRARY_DIRS})
target_link_libraries(ListDirectory  ListDir)

install(
    TARGETS ListDirectory
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)
