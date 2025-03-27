cmake_minimum_required(VERSION 3.10)

project(ListDirectory)

set(CMAKE_CXX_STANDARD 11)

#set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_MULTITHREADED ON)

find_package(Boost COMPONENTS filesystem system REQUIRED)

add_executable(ListDirectory main.cpp)
target_include_directories(ListDirectory PRIVATE include)
# target_include_directories(ListDirectory PRIVATE ${Boost_INCLUDE_DIRS})

add_subdirectory(src)

# target_link_directories(ListDirectory PRIVATE ${Boost_LIBRARY_DIRS})
target_link_libraries(ListDirectory PRIVATE ListDir)

install(
    TARGETS ListDirectory
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
)
