# cmake_policy(SET CMP0074 NEW)

find_path(
    FC_INCLUDE_DIR NAMES FirstClass.h
    HINTS
        $ENV{FC_ROOT}/include
        ${FC_ROOT}/include
    REQUIRED
)

find_library(
    FC_LIBRARIES
    NAMES fc
    HINTS
        ${FC_ROOT}/lib
)
set(FC_VERSION 0.1)

message(${FC_INCLUDE_DIR})
message(${FC_LIBRARIES})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(FC
    FOUND_VAR FC_FOUND
    REQUIRED_VARS
        FC_LIBRARIES
        FC_INCLUDE_DIR
    VERSION_VAR FC_VERSION
)


