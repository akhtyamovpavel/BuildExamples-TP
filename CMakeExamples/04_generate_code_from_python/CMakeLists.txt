

cmake_minimum_required(VERSION 3.0)

project(GenerateArray)

add_custom_command( 
  OUTPUT array.h
  COMMAND python ${PROJECT_SOURCE_DIR}/generate_array.py ${PROJECT_SOURCE_DIR}/data.json array.h
  DEPENDS generate_array.py data.json
  COMMENT "Generating array from json"
)

set(SOURCES main.cpp)

add_custom_target( RunGenerator DEPENDS array.h COMMENT "Checking if re-generation is required" )

add_executable(GenerateArray ${SOURCES})
add_dependencies( GenerateArray RunGenerator )

target_include_directories(GenerateArray PRIVATE ${CMAKE_BINARY_DIR})

