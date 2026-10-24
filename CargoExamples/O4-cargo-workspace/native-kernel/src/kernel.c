#include <stddef.h>

double c_dot_product(const double* a, const double* b, size_t n) {
    double acc = 0.0;
    for (size_t i = 0; i < n; ++i) {
        acc += a[i] * b[i];
    }
    return acc;
}
