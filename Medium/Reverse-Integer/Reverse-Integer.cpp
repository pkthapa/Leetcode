#include "main.hpp"

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0)
        {
            int pop = x % 10;
            x /= 10;

            if (rev > INT32_MAX/10 || (rev == INT32_MAX/10 && pop > 7))
            {
                return 0;
            }
            if (rev < INT32_MIN/10 || (rev == INT32_MIN/10 && pop < -8))
            {
                return 0;
            }
            rev = 10 * rev + pop;
        }
        return rev;
    }
};

int main() {
    Solution sln;

    assert(321 == sln.reverse(123));
    assert(-321 == sln.reverse(-123));
    assert(21 == sln.reverse(120));

    return 0;
}