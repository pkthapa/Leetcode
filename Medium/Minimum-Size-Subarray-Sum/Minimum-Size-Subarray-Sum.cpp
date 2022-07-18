#include "main.hpp"

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Sliding window approach: https://www.educative.io/courses/grokking-the-coding-interview/7XMlMEQPnnQ
        // 2 1 5 2 3 2

        int start = 0;
        int windowSum = 0;
        int minSize = INT32_MAX; // Holds the result (size of the minimum subarray).

        for (int end = 0; end < nums.size(); ++end) {
            windowSum += nums[end];

            while (windowSum >= target) {
                // Try reducing the subarray to get the minimum sum, if possible.
                minSize = std::min(minSize, end - start + 1);
                windowSum -= nums[start];
                ++start;
            }
        }
        return minSize == INT32_MAX ? 0 : minSize;
    }
};

int main() {
    Solution sln;
    {
        int target = 7;
        vector<int> v{2, 3, 1, 2, 4, 3};
        assert(2 == sln.minSubArrayLen(target, v));
    }
    {
        int target = 4;
        vector<int> v{1, 4, 5};
        assert(1 == sln.minSubArrayLen(target, v));
    }
    {
        int target = 11;
        vector<int> v{1, 1, 1, 1, 1, 1, 1, 1};
        assert(0 == sln.minSubArrayLen(target, v));
    }
    return 0;
}