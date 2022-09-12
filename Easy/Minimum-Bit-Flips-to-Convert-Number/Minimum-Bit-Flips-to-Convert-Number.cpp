#include "main.hpp"

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xored = start ^ goal;
        
        int c = 0;
        while (xored > 0) {
            xored = xored & (xored - 1);
            c++;
        }
        return c;
    }
};

int main() {
    Solution sln;

    assert(3 == sln.minBitFlips(10, 7));
    assert(3 == sln.minBitFlips(3, 4));
    assert(4 == sln.minBitFlips(15, 0));

    return 0;
}