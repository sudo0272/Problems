#include <algorithm>
#include <vector>

class Solution {
  public:
    int singleNumber(std::vector<int>& nums) {
      std::sort(nums.begin(), nums.end());

      for (unsigned int i = 1; i < nums.size(); i += 2) {
        if (nums[i] != nums[i - 1]) {
          return nums[i - 1];
        }
      }

      return nums[nums.size() - 1];
    }
};

