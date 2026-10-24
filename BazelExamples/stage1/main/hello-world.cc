#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string who = (argc > 1) ? argv[1] : "world";
    std::cout << "Stage 1: Hello " << who << "!" << std::endl;
    return 0;
}
