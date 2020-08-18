#include <vector>

class Solution {
  public:
    void rotate(std::vector<int>& nums, int k) {
      bool isPushed;
      int currentValue;
      int originalValue;
      unsigned int currentIndex;
      int temp;
      int steps = k % nums.size();

      if (steps != 0) {
        isPushed = nums.size() % steps ? false : true;
      } else {
        return;
      }

      if (isPushed) {
        nums.push_back(0); // dump
      }

      currentIndex = 0;
      currentValue = nums[0];
      do {
        currentIndex += steps;

        if (currentIndex > nums.size() - 1) {
          currentIndex -= nums.size();
        }

        originalValue = nums[currentIndex];
        nums[currentIndex] = currentValue;
        currentValue = originalValue;
      } while (currentIndex != 0);
      
      if (isPushed) {
        for (unsigned int i = steps - 1; i >= 1; i--) {
          nums[i] = nums[i - 1];
        }

        nums[0] = nums[nums.size() - 1];

        nums.pop_back();
      }
    }
};


