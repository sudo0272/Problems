#include <vector>
#include <unordered_map>

class Solution {
  public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
      std::vector<int> result;
      std::vector<int> *large;
      std::vector<int> *small;
      std::unordered_map<int, unsigned int> numsCount;

      if (nums1.size() > nums2.size()) {
        large = &nums1;
        small = &nums2;
      } else {
        large = &nums2;
        small = &nums1;
      }

      for (auto i: *small) {
        numsCount[i]++;
      }

      for (auto i: *large) {
        if (numsCount[i]) { // key is not found or
                            // value is 0, which means it has already pushed
          result.push_back(i);
          numsCount[i]--;
        }
      }

      return result;
    }
};

