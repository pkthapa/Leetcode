#include "main.hpp"

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;

    // Approach: Using two pointers/variables.
    auto startIndex = 0;
    auto endIndex = numbers.size() - 1;

    while (startIndex < endIndex) {
      auto sum = numbers[startIndex] + numbers[endIndex];

      if (sum == target) {
        result.push_back(startIndex + 1);
        result.push_back(endIndex + 1);
        break;
      }

      if (sum > target) {
        --endIndex;
      }
      else {
        ++startIndex;
      }
    }
    return result;
  }
};

int main() {
  Solution sln;

  vector<int> v1 {2, 7, 11, 15}, res1 {1, 2};
  assert(res1 == sln.twoSum(v1, 9));

  vector<int> v2 {2, 3, 4}, res2 {1, 3};
  assert(res2 == sln.twoSum(v2, 6));

  vector<int> v3 {-1, 0}, res3 {1, 2};
  assert(res3 == sln.twoSum(v3, -1));

  return 0;
}