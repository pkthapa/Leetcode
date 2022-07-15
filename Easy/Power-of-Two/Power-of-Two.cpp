#include "main.hpp"

class Solution {
public:
    // x = log2(n)
    // is equal to
    // 2^x = n
    bool isPowerOfTwo(int n) {
        if(n == 0) {
            return false;
        }

        if(ceil(log2(n)) == floor(log2(n))) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution sln;

    assert(true == sln.isPowerOfTwo(1));

    assert(true == sln.isPowerOfTwo(16));
    
    assert(false == sln.isPowerOfTwo(3));

    return 0;
}