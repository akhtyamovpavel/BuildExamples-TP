#include <iostream>
#include <vector>
#include <ListDir.h>


int main() {
  std::string path = ".";
  auto result = ListDir(path);
  
  for (auto output: result) {
    std::cout << output << std::endl;  
  }
  return 0;
}
