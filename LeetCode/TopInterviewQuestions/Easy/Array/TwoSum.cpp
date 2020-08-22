#include <vector>
#include <algorithm>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::vector<int> result;
      bool isSolutionFound = false;
      int minNums = *std::min_element(nums.begin(), nums.end());
      int limit = target - minNums;
      
      for (unsigned int i = 0; i < nums.size() && !isSolutionFound; i++) {
        if (nums[i] > limit) {
          continue;
        }

        for (unsigned int j = 0; j < nums.size(); j++) {
          if (nums[j] > limit || i == j) {
            continue;
          }

          if (nums[i] + nums[j] == target) {
            result.push_back(i);
            result.push_back(j);

            isSolutionFound = true;
          }
        }
      }

      return result;
    }
};

