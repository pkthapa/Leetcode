#include "main.hpp"

class Solution {
public:
    /**
     * @brief Using Brian Kernighan’s Algorithm.
     * Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit. 
     * for example:
     * 10 in binary is 00001010
     * 9 in binary is 00001001
     * 8 in binary is 00001000
     * 7 in binary is 00000111
     * So if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit.
     * If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count.
     * The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer.
     */
    int hammingWeight(uint32_t n) {
        int hWeight {0};

        while (n > 0) {
            n &= (n - 1);
            ++hWeight;
        }
        return hWeight;
    }
};

int main() {
  Solution sln;

  assert(2 == sln.hammingWeight(9));

  assert(2 == sln.hammingWeight(10));

  assert(0 == sln.hammingWeight(0));

  assert(1 == sln.hammingWeight(1));

  return 0;
}