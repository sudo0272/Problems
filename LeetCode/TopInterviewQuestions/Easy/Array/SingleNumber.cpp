#include <algorithm>
#include <vector>

class Solution {
  public:
    int singleNumber(std::vector<int>& nums) {
      int result = 0;

      for (int i: nums) {
        result ^= i;
      }

      return result;
    }
};

