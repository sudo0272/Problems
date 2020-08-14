#include <iostream>

int main() {
  unsigned int n;
  int big = 0;
  unsigned int currentWeight = 0;

  std::cin >> n;

  while (currentWeight <= n) {
    big++;
    currentWeight += 5;
  }
  big--;
  currentWeight -= 5;

  while (big >= 0 && (n - currentWeight)% 3 != 0) {
    big--;
    currentWeight -= 5;
  }

  if (big < 0) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << big + (n - currentWeight) / 3 << std::endl;
  }

  return 0;
}

