cmake_minimum_required(VERSION 3.10)

project(FirstClassAsLibrary)

set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")


set(MAIN_SOURCE main.cpp)

add_executable(FirstClassAsLibrary ${MAIN_SOURCE})
target_include_directories(FirstClassAsLibrary PRIVATE include)


add_subdirectory(src)
target_link_libraries(FirstClassAsLibrary fc)


install(
    TARGETS FirstClassAsLibrary
    RUNTIME DESTINATION bin
)
