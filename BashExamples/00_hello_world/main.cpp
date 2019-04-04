#include <iostream>
#include <vector>

int main() {
  std::vector<int> a = {1, 2, 3};
  for (int i = 0; i < a.size() - 5; ++i) {
	std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Hello world!" << std::endl;
  return 0;  
}
