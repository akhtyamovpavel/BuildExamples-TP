#include "lib/hello-time.h"
#include "main/hello-greet.h"
#include <cassert>
#include <iostream>

int main() {
    assert(get_greet("MIPT") == "Hello MIPT");
    assert(format_build_tag(8) == "PromProg-1C-Lecture-8");
    std::cout << "All stage3 assertions passed!" << std::endl;
    return 0;
}
