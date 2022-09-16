#include "main.hpp"

class Solution {
    vector<vector<int>> dp;

    int solve(vector<int>& nums, vector<int>& multipliers, int l, int r, int idx) {
        // Base condition.
        // 'idx' is the index of 'multipliers' and can never be greater than the size of 'multipliers'.
        if (idx >= multipliers.size()) {
            return 0;
        }
        
        // Memoization.
        if (dp[l][idx] != INT32_MIN) {
            return dp[l][idx];
        }
        
        int x = multipliers[idx];

        // Recursion: Choices.
        return dp[l][idx] = std::max(nums[l] * x + solve(nums, multipliers, l + 1, r, idx + 1), // nums[start] * x + solve()
                                nums[r] * x + solve(nums, multipliers, l, r - 1, idx + 1)); // nums[end] * x + solve()
    }

public:
    // https://www.youtube.com/watch?v=m6JQ3qsEG_A&t=22s&ab_channel=CherryCoding%5BIIT-G%5D
    //
    // DP = choices + optimization
    // DP means recursion.
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int l = 0;
        int r = nums.size() - 1;
        int idx = 0; // For 'multipliers'. Decided to go with 'idx' for 'multipliers' because the size of 'multipliers' is >= size of 'nums'.
        
        int m = multipliers.size();
        
        // IMPORTANT: Always initialize the 2D-DP array with INT32_MIN for test cases having output as '-1'.
        dp.assign(m + 1, vector<int>(m + 1, INT32_MIN));

        return solve(nums, multipliers, l, r, idx);
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {1, 2, 3};
        vector<int> multipliers {3, 2, 1};
        assert(14 == sln.maximumScore(nums, multipliers));
    }
    {
        vector<int> nums {-5, -3, -3, -2, 7, 1};
        vector<int> multipliers {-10, -5, 3, 4, 6};
        assert(102 == sln.maximumScore(nums, multipliers));
    }
    {
        vector<int> nums {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector<int> multipliers {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        assert(-1 == sln.maximumScore(nums, multipliers));
    }
    return 0;
}