#include "lib/hello-time.h"
#include "main/hello-greet.h"
#include <iostream>

int main() {
    std::cout << "Stage 3: " << get_greet("Hermetic Packages")
              << " [" << format_build_tag(8) << "]" << std::endl;
    return 0;
}
