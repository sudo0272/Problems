#include <iostream>
#include <vector>

class Solution {
  public:
    int maxProfit(std::vector<int>& prices) {
      int profit = 0;

      for (unsigned int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
          profit += prices[i] - prices[i - 1];
        }
      }

      return profit;
    }
};

int main() {
  std::vector<int> prices;
  unsigned int pricesSize;
  int price;
  Solution *solution = new Solution();

  std::cin >> pricesSize;

  for (unsigned int i = 0; i < pricesSize; i++) {
    std::cin >> price;

    prices.push_back(price);
  }

  std::cout << solution->maxProfit(prices) << std::endl;

  delete solution;

  return 0;
}

