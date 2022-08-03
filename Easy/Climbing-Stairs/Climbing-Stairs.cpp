#include "main.hpp"

class Solution {
public:
    int climbStairs(int n) {
    // Can be solved using DP. Similar to fibonacci series.
        int first = 1;
        int second = 1;
        for (int i = 0; i < n - 1; ++i){
            first += second;
            second = first - second;
        }
        return first;
    }
};

int main() {
    Solution sln;

    assert(2 == sln.climbStairs(2));

    assert(3 == sln.climbStairs(3));

    assert(8 == sln.climbStairs(5));

    return 0;
}
