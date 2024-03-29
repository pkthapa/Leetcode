#include "main.hpp"

class Solution {
public:
    /*
    Given int, return array: for each i, ans[i] is # of 1's
    Ex. n = 2 -> [0,1,1], 0 = 0 has 0, 1 = 1 has 1, 2 = 10 has 1

    x = 1001011101 = 605
    x'= 0100101110 = 302
    Differ by 1 bit, by removing LSB: f(x) = f(x / 2) + (x mod 2)

    Time: O(n)
    Space: O(n)
    */
    vector<int> countBits(int n) {
        vector<int> result (n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            result[i] = result[i >> 1] + (i % 2);
        }
   
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> result {0};
        assert(result == sln.countBits(0));
    }
    {
        vector<int> result {0, 1, 1};
        assert(result == sln.countBits(2));
    }
    {
        vector<int> result {0, 1, 1, 2, 1, 2};
        assert(result == sln.countBits(5));
    }
    return 0;
}