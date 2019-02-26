//
// Created by Pavel Akhtyamov on 01/10/2018.
//

#include "MathFunctions.h"
#include <cmath>


double MySqrt(double x) {
  if (x > 0) {
    return sqrt(x);
  } else {
    return sqrt(std::abs(x));
  }
}


