


cmake_minimum_required(VERSION 3.10)
project(Math)

option(USE_MYMATH "Use Module Math" ON)

set(CMAKE_CXX_STANDARD 11)


set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})



if (USE_MYMATH)
    add_definitions(-DUSE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    add_subdirectory(MathFunctions)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)


add_executable(Math main.cpp)
target_link_libraries(Math ${EXTRA_LIBS})

install(TARGETS Math DESTINATION bin)



