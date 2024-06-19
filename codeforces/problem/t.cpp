#include <functional>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec(10, 1);
  vec.assign(6, 2);
  for (auto x : vec) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  vec.resize(8, 3);
  for (auto x : vec) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  return 0;
}