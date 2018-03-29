#include <iostream>
#include <config.h>


int main() {
  std::cout << "Hello World!" << std::endl;
  std::cout << "This is" << PACKAGE_STRING << std::endl;
  return 0;  
}
