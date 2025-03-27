cmake_minimum_required(VERSION 3.10)

project(GenerateArray)
find_package(Python COMPONENTS Interpreter REQUIRED)

add_custom_target( 
  RunGenerator
  BYPRODUCTS array.h
  COMMAND Python::Interpreter ${PROJECT_SOURCE_DIR}/generate_array.py ${PROJECT_SOURCE_DIR}/data.json array.h
  DEPENDS generate_array.py data.json
  COMMENT "Generating array from json"
)

set(SOURCES main.cpp)

add_executable(GenerateArray ${SOURCES})
add_dependencies(GenerateArray RunGenerator)

target_include_directories(GenerateArray PRIVATE ${CMAKE_BINARY_DIR})
# target_link_libraries(GenerateArray PRIVATE $GTEST_LIBRARIES)
# target_include_directories(GenerateArray PRIVATE ${GTEST_INCLUDE_DIRS})
