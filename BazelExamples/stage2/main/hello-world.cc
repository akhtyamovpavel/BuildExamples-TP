#include "main/hello-greet.h"
#include <iostream>

int main() {
    std::cout << "Stage 2: " << get_greet("Bazel target graph") << std::endl;
    return 0;
}
