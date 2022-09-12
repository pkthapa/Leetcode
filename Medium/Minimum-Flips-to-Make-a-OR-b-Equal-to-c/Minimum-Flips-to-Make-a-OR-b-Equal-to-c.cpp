#include "main.hpp"

class Solution {
public:
    int minFlips(int a, int b, int c) {

        int result = 0;

        for (int i = 0; i < 32; ++i) {
            // Find if ith bit is set (true) or unset (0).
            bool ai = false;
            bool bi = false;
            bool ci = false;

            if ((a & (1 << i)) > 0) {
                ai = true;
            }
            
            if ((b & (1 << i)) > 0) {
                bi = true;
            }
            
            if ((c & (1 << i)) > 0) {
                ci = true;
            }
            
            // If ith bit of 'c' is set, that means ith bit of either 'a' or 'b' has to be set.
            if (ci) {
                if (!ai && !bi) {
                    result++;
                }
            }
            else {
                if (ai && bi) {
                    result += 2;
                }
                else if (ai || bi) {
                    result++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        int a = 2, b = 6, c = 5;
        assert(3 == sln.minFlips(a, b, c));
    }
    {
        int a = 4, b = 2, c = 7;
        assert(1 == sln.minFlips(a, b, c));
    }
    {
        int a = 1, b = 2, c = 3;
        assert(0 == sln.minFlips(a, b, c));
    }
    return 0;
}