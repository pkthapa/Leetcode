#include "main.hpp"

/*
Algorithm

The implementation is straightforward - we just need to modify twoSumII to produce triplets and skip repeating values.

1. For the main function:

    a. Sort the input array nums.
    b. Iterate through the array:
       - If the current value is greater than zero, break from the loop. Remaining values cannot sum to zero.
       - If the current value is the same as the one before, skip it.
       - Otherwise, call twoSumII for the current position i.

2. For twoSumII function:

    a. Set the low pointer lo to i + 1, and high pointer hi to the last index.
    b. While low pointer is smaller than high:
       - If sum of nums[i] + nums[lo] + nums[hi] is less than zero, increment lo.
       - If sum is greater than zero, decrement hi.
       - Otherwise, we found a triplet:
            * Add it to the result 'res'.
            * Decrement hi and increment lo.
            * Increment lo while the next value is the same as before to avoid duplicates in the result.

2. Return the result 'res'.
*/

class Solution {
    void twoSumII(const vector<int>& nums, int idx, vector<vector<int>>& result) {
        int lo = idx + 1;
        int hi = nums.size() - 1;
        
        while (lo < hi) {
            int sum = nums[idx] + nums[lo] + nums[hi];
            
            if (0 < sum) {
                --hi;
            }
            else if (0 > sum) {
                ++lo;
            }
            else {
                result.push_back({nums[idx], nums[lo++], nums[hi--]});
                
                while (lo < hi && nums[lo - 1] == nums[lo]) {
                    ++lo;
                }
            }
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        // Lets sort the input vector.
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        // If nums[i] > 0, then break because remaining values cannot sum to 0.
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            // If the current value is same as the one before, then skip it.
            if (0 == i || nums[i - 1] != nums[i]) {
                twoSumII(nums, i, result);
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> v{-1, 0, 1, 2, -1, -4};
        vector<vector<int>> output {{-1, -1, 2}, {-1, 0, 1}};
        assert(output == sln.threeSum(v));
    }
    {
        vector<int> v{};
        vector<vector<int>> output {};
        assert(output == sln.threeSum(v));
    }
    {
        vector<int> v{0};
        vector<vector<int>> output {};
        assert(output == sln.threeSum(v));
    }
    return 0;
}