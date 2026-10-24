#include "inicpp.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path path = fs::current_path() / "examples/config.ini";
    if (!fs::exists(path)) {
        path = fs::current_path() / "main/examples/config.ini";
    }
    inicpp::config example_config = inicpp::parser::load_file(path.string());
    std::cout << "inicpp loaded [main] x="
              << example_config["main"]["x"].get<inicpp::string_ini_t>() << std::endl;
    return 0;
}
