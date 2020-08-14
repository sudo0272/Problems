#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
      unsigned int targetIndex = 1; // I have to replace numbers from 1
                                    // because the algorithm below uses nums[0]
                                    // as the standard of comparison at first loop

      if (nums.size() < 2) {
        return nums.size();
      }

      for (unsigned int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] != nums[i]) {
          nums[targetIndex] = nums[i];

          targetIndex++;
        }
      }

      return targetIndex; // targetIndex is the position of next element
                          // so targetIndex is able to be menat the length of the array
    }
};

int main() {
  std::vector<std::vector<int>> testcases = {
    {1, 1, 2},
    {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
  };

  Solution *solution = new Solution();

  for (unsigned int i = 0; i < testcases.size(); i++) {
    std::cout << solution->removeDuplicates(testcases[i]) << " -> ";

    for (auto j: testcases[i]) {
      std::cout << j << ' ';
    }

    std::cout << std::endl;
  }

  return 0;
}

