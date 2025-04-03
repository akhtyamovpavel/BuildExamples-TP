cmake_minimum_required(VERSION 3.5)

set(PACKAGE_NAME my_package)
project(${PACKAGE_NAME})

configure_file(config.h.in ${PROJECT_SOURCE_DIR}/config.h)

add_library(${PACKAGE_NAME} SHARED library.cpp Var.cpp)
include_directories(${PACKAGE_NAME_BINARY_DIR})

build_python_target(${PACKAGE_NAME})
