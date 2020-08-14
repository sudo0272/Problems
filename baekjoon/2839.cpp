#include <iostream>

int main() {
  unsigned int n;
  unsigned int big = 0;
  unsigned int small = 0;

  std::cin >> n;

  while (5 * big <= n) {
    big++;
  }
  big--;

  std::cout << big << std::endl;

  return 0;
}

