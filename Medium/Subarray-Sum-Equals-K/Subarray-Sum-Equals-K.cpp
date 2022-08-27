#include "main.hpp"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalCount = 0;
        int idx = 0;
        int currSum = 0;
        unordered_map<int, int> prefixSumsCount;

        while (idx < nums.size()) {
            currSum += nums[idx++];

            if (currSum == k) { // We found subarray with sum 'k'.
                ++totalCount;
            }

            totalCount += prefixSumsCount[currSum - k];

            ++prefixSumsCount[currSum];
        }
        return totalCount;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {1, 1, 1};
        int k = 2;
        assert(2 == sln.subarraySum(nums, k));
    }
    {
        vector<int> nums {1, 2, 3};
        int k = 3;
        assert(2 == sln.subarraySum(nums, k));
    }
    {
        vector<int> nums {1, -1, 1, 1, 1, 1, 2, 3};
        int k = 3;
        assert(6 == sln.subarraySum(nums, k));
    }
    return 0;
}