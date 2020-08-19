#include <map>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
      std::map<int, bool> appearance;

      for (int i: nums) {
        if (appearance.find(i) == appearance.end()) {
          appearance.insert(std::pair<int, bool>(i, true));
        } else {
          return true;
        }
      }

      return false;
    }
};

