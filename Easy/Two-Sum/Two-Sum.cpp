#include "main.hpp"

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;

    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {

      if (m.count(nums[i]) == 0) {
        m[target - nums[i]] = i;
      }
      else {
        result.push_back(i);
        result.push_back(m[nums[i]]);
        break;
      }
    }
    return result;
  }
};

int main() {
  Solution sln;
  {
    vector<int> v {2, 7, 11, 15};
    vector<int> result {1, 0};
    assert(result == sln.twoSum(v, 9));
  }

  {
    vector<int> v {3, 2, 4};
    vector<int> result {2, 1};
    assert(result == sln.twoSum(v, 6));
  }

  {
    vector<int> v {3, 3};
    vector<int> result {1, 0};
    assert(result == sln.twoSum(v, 6));
  }

  return 0;
}