#include <cmath>
#include "sqrt.h"


float square(float x) {
  return x * x;
}

float my_sqrt(float x) {
  return static_cast<float>(sqrt(x));
}
