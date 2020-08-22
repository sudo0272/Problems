#include <vector>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    auto i = digits.end() - 1;

    for (; i >= digits.begin(); i--) {
      (*i)++;

      if (*i == 10) {
        *i = 0;
      } else {
        break;
      }
    }

    if (i + 1 == digits.begin()) {
      digits.push_back(0);
      *digits.begin() = 1;
    }

    return digits;
  }
};

