cmake_minimum_required(VERSION 3.5)

set(Python_FIND_VERSION_MAX 3.12)
find_package(Python COMPONENTS Development REQUIRED)
find_package(Boost REQUIRED COMPONENTS system python312)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(Python::Development)
link_directories(${Boost_LIBRARY_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib")


function(build_python_target target)
    set_target_properties(${target} PROPERTIES PREFIX "") # lib - by default
    set_target_properties(${target} PROPERTIES SUFFIX ".so")
    target_link_libraries(${target} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
endfunction(build_python_target)

add_subdirectory(00-hello-world)
add_subdirectory(01-classes)
add_subdirectory(02-get-set)
add_subdirectory(03-inheritance)
add_subdirectory(04-fast-calculation)

