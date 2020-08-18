#include <vector>

class Solution {
  public:
    void rotate(std::vector<int>& nums, int k) {
      bool isPushed = nums.size() % k ? false : true;
      int currentValue;
      int originalValue;
      unsigned int currentIndex;
      int temp;

      if (isPushed) {
        nums.push_back(0); // dump
      }

      currentIndex = 0;
      currentValue = nums[0];
      do {
        currentIndex += k;

        if (currentIndex > nums.size() - 1) {
          currentIndex -= nums.size();
        }

        originalValue = nums[currentIndex];
        nums[currentIndex] = currentValue;
        currentValue = originalValue;
      } while (currentIndex != 0);
      
      if (isPushed) {
        for (unsigned int i = k - 1; i >= 1; i--) {
          nums[i] = nums[i - 1];
        }

        nums[0] = nums[nums.size() - 1];

        nums.pop_back();
      }
    }
};

