#include "main.hpp"

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b);
            a = a ^ b;
            b = (unsigned)carry << 1;
        }
        return a;
    }
};

int main() {
    Solution sln;

    assert(3 == sln.getSum(1, 2));
    assert(1 == sln.getSum(-1, 2));
    assert(2 == sln.getSum(0, 2));

    return 0;
}