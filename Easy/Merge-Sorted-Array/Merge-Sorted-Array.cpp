#include "main.hpp"

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m + n - 1; // Index to store. Points to the last index of `nums1`.
    --m; --n;
    
    // Since both the vectors are sorted, so start by
    // moving larger elements from both vector to the end of nums1.
    while (m >= 0 and n >= 0){
      if (nums1[m] >= nums2[n]){
        nums1[k--] = nums1[m--];
      }
      else {
        nums1[k--] = nums2[n--];
      }
    }
    
    // Process remaining numbers.
    while (m >= 0) nums1[k--] = nums1[m--];
    while (n >= 0) nums1[k--] = nums2[n--];
  }
};

int main() {
  Solution sln;

  {
    vector<int> v1{1, 2, 3, 0, 0, 0}, v2{2, 5, 6}, expectedResult{1, 2, 2, 3, 5, 6};
    int m = 3, n = 3;
    sln.merge(v1, m, v2, n);
    assert(expectedResult == v1);
  }
  {
    vector<int> v1{0}, v2{2}, expectedResult{2};
    int m = 0, n = 1;
    sln.merge(v1, m, v2, n);
    assert(expectedResult == v1);
  }
  {
    vector<int> v1{1, 2, 3}, v2{0}, expectedResult{1, 2, 3};
    int m = 3, n = 0;
    sln.merge(v1, m, v2, n);
    assert(expectedResult == v1);
  }
  return 0;
}