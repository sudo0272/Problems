#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
      unsigned int numsSize = nums.size();

      std::sort(nums.begin(), nums.end());

      for (unsigned int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
          return true;
        }
      }

      return false;
    }
};

