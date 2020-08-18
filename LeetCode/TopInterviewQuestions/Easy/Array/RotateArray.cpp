#include <vector>

int gcd(int, int);

class Solution {
  public:
    void rotate(std::vector<int>& nums, int k) {
      int currentValue;
      unsigned int currentIndex;
      int iMax = gcd(nums.size(), k);
      int steps = k % nums.size();

      for (unsigned int i = 0; i < iMax; i++) {
        currentIndex = i;
        currentValue = nums[i];
        do {
          currentIndex += steps;

          if (currentIndex > nums.size() - 1) {
            currentIndex -= nums.size();
          }

          if (nums[currentIndex] != currentValue) {
            nums[currentIndex] ^= currentValue;
            currentValue ^= nums[currentIndex];
            nums[currentIndex] ^= currentValue;
          }
        } while (currentIndex != i);
      }
    }
};

int gcd(int n, int m) {
  int a, b, c;

  if (n > m) {
    a = n;
    b = m;
  } else {
    a = m;
    b = n;
  }

  do {
    c = a % b;
    a = b;
    b = c;
  } while (c != 0);

  return a;
}

