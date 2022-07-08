#include "main.hpp"

class Solution {
public:
  int mySqrt(int x) {
    int low = 0;
    int high = x;
    long mid = 0;
    long ans = 0;
    
    while (low <= high) {
      mid = (high - low)/2 + low;
      
      if (mid * mid == x) {
        return mid;
      }
      else if (mid * mid < x) {
        ans = std::max(ans, mid);
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }
    return ans;
  }
};

int main() {
  Solution sln;

  assert(2 == sln.mySqrt(4));

  assert(2 == sln.mySqrt(8));

  assert(9 == sln.mySqrt(81));

  assert(9 == sln.mySqrt(82));

  return 0;
}