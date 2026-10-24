#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string arg = (argc > 1) ? argv[1] : "default_arg";
    std::cout << "#pragma once\n"
              << "#define GENERATED_BUILD_STAMP \"Bazel-Genrule-" << arg << "\"\n";
    return 0;
}
