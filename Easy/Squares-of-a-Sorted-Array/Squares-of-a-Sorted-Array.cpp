#include "main.hpp"

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());

        // Two pointers approach.
        // If we square the numbers, we can consider it to be same. E.g. -4 * -4 = 16, 4 * 4 = 16.
        // Input: [-4,-1,0,3,10]
        // We can consider it as: [4,1,0,3,10]
        int l = 0;
        int r = nums.size() - 1;
        int i = nums.size() - 1; // To keep track of the index where the result will be filled.

        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                result[i--] = nums[l] * nums[l];
                ++l;
            }
            else {
                result[i--] = nums[r] * nums[r];
                --r;
            }
        }
        return result;
    }
};

int main() {
    Solution sln;

    {
        vector<int> v {-4, -1, 0, 3, 10};
        vector<int> o {0, 1, 9, 16, 100};
        assert(o == sln.sortedSquares(v));
    }

    {
        vector<int> v {0};
        vector<int> o {0};
        assert(o == sln.sortedSquares(v));
    }

    {
        vector<int> v {-7, -3, 2, 3, 11};
        vector<int> o {4, 9, 9, 49, 121};
        assert(o == sln.sortedSquares(v));
    }
    return 0;
}