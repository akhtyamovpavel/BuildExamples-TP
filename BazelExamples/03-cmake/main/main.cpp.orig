#include "inicpp.h"

#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path path = fs::current_path();

    path /= "examples/config.ini";
    inicpp::config example_config = inicpp::parser::load_file(path.string());

    return 0;
}
