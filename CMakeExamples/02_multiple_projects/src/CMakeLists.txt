cmake_minimum_required(VERSION 3.10)
project(FirstClassLibrary)

set(SOURCE_LIB FirstClass.cpp)
add_library(fc SHARED ${SOURCE_LIB})
target_include_directories(fc PRIVATE ${FirstClassAsLibrary_SOURCE_DIR}/include)

file(GLOB_RECURSE LIBRARY_HEADERS "${FirstClassAsLibrary_SOURCE_DIR}/include/*.h")

set_target_properties(fc PROPERTIES PUBLIC_HEADER ${LIBRARY_HEADERS})

install(
    TARGETS fc
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
