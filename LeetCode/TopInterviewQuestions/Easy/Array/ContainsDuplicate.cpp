#include <vector>
#include <algorithm>
#include <cstring>

class Solution {
  public:
    bool containsDuplicate(std::vector<int>& nums) {
      int maxNum;
      int minNum;
      unsigned int realNumsSize;
      bool *realNums;

      if (nums.size() <= 1) {
        return false;
      }

      minNum = *std::min_element(nums.begin(), nums.end()); 
      maxNum = *std::max_element(nums.begin(), nums.end());
      realNumsSize = maxNum - minNum + 1; 
      realNums = new bool[realNumsSize];

      memset(realNums, false, realNumsSize);

      for (unsigned int i = 0; i < nums.size(); i++) {
        if (realNums[nums[i] - minNum]) {
          delete[] realNums;

          return true;
        } else {
          realNums[nums[i] - minNum] = true;
        }
      }

      delete[] realNums;

      return false;
    }
};

