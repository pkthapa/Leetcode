#include "main.hpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;

        for (auto num : nums) {
            if (currSum < 0) {
                currSum = 0;
            }
            currSum += num;
            maxSum = std::max(maxSum, currSum);
        }
        return maxSum;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        assert(6 == sln.maxSubArray(nums));
    }
    {
        vector<int> nums {1};
        assert(1 == sln.maxSubArray(nums));
    }
    {
        vector<int> nums {5, 4, -1, 7, 8};
        assert(23 == sln.maxSubArray(nums));
    }
    return 0;
}