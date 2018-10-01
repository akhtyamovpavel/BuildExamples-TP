add_library(MathFunctions MathFunctions.cpp)

INSTALL(TARGETS MathFunctions DESTINATION bin)
INSTALL(FILES MathFunctions.h DESTINATION include)
