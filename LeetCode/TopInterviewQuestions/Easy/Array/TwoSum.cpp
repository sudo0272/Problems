#include <vector>
#include <unordered_map>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
      std::unordered_map<int, int> indices;

      for (int i = 0; i < nums.size(); i++) {
        if (indices.find(target - nums[i]) != indices.end()) {
          return {i, indices[target - nums[i]]};
        } else {
          indices.insert({nums[i], i});
        }
      }

      return {};
    }
};

