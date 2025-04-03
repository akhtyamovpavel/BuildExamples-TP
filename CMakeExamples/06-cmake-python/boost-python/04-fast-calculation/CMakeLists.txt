
add_library(
    summer SHARED 
    sum.cpp
    wrapper.cpp
)
build_python_target(summer)
