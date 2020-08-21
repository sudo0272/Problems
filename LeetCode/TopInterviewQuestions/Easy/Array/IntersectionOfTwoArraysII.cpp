#include <vector>
#include <algorithm>

class Solution {
  public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
      std::vector<int> result;
      std::vector<int>::iterator nums1Element;
      std::vector<int>::iterator nums2Element;

      std::sort(nums1.begin(), nums1.end());
      std::sort(nums2.begin(), nums2.end());

      nums1Element = nums1.begin();
      nums2Element = nums2.begin();

      while (nums1Element != nums1.end() && nums2Element != nums2.end()) {
        if (*nums1Element == *nums2Element) {
          result.push_back(*nums1Element);
          nums1Element++;
          nums2Element++;
        } else if (*nums1Element > *nums2Element) {
          nums2Element++;
        } else {
          nums1Element++;
        }
      }

      return result;
    }
};

