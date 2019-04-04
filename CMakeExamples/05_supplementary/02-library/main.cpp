

#include <iostream>

#ifdef USE_MYMATH
#include <MathFunctions.h>
#else
#include <cmath>
#endif

int main() {
#ifdef USE_MYMATH
  std::cout << MySqrt(-9) << std::endl;
#else
  std::cout << sqrt(-9.0) << std::endl;
#endif

  return 0;
}


