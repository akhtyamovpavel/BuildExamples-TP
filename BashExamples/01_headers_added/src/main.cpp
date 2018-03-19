#include <string>
#include <iostream>
#include "FirstClass.h"


int main() {
  FirstClass example;
  example.Set("Hello, world");
  
  std::cout << example.Get() << std::endl;
}
