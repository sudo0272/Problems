#include <iostream>
#include <vector>

class Solution {
  public:
    int maxProfit(std::vector<int> &prices) {

    }
};

int main() {
  std::vector<int> prices;
  unsigned int pricesSize;
  unsigned int price;

  std::cin >> pricesSize;

  for (unsigned int i = 0; i < pricesSize; i++) {
    std::cin >> price;

    prices.push_back(price);
  }

  std::cout << Solution().maxProfit(prices) << std::endl;

  return 0;
}

