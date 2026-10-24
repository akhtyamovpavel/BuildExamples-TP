#include "main/lib_impl.h"
#include <cassert>
#include <iostream>

int main() {
    std::string b = get_stamped_banner();
    assert(b == "SymbolicMacro[Bazel-Genrule-MIPT_1C_2026]");
    std::cout << "Symbolic macro test passed: " << b << std::endl;
    return 0;
}
