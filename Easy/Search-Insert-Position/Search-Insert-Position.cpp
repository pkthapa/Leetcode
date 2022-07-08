#include "main.hpp"

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    int mid = 0;

    while (low < high){
      mid = (low + high)/2;

      if (target > nums[mid]){
        low = mid + 1; // 'mid' is not equal to target for sure.
      }
      else {
        high = mid; // It is possible to insert at 'mid'.
      }

    }
    return low;
  }
};

int main() {
  Solution sln;

  vector<int> v {1, 3, 5, 6};
  assert(2 == sln.searchInsert(v, 4));

  assert(0 == sln.searchInsert(v, 0));
  
  assert(2 == sln.searchInsert(v, 5));

  assert(4 == sln.searchInsert(v, 7));

  return 0;
}