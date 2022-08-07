#include "main.hpp"

class Solution {
    int helper(vector<int>&& nums) {
        int rob1 = 0;
        int rob2 = 0;

        for (auto num : nums) {
            // Calculate what is the max we could rob until 'num'.
            auto newRob = std::max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = newRob;
        }
        return rob2;
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        // Calculate the max robbed amount by either
        // skipping first element and including the last, or
        // including first element and skipping the last.
        // We cannot include both first and last elements (houses)
        // since they are adjacent due to circular placement.
        int rob1 = helper({nums.begin(), nums.end() - 1});
        int rob2 = helper({nums.begin() + 1, nums.end()});

        return std::max(rob1, rob2);
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {2, 3, 2};
        assert(3 == sln.rob(nums));
    }
    {
        vector<int> nums {1, 2, 3, 1};
        assert(4 == sln.rob(nums));
    }
    {
        vector<int> nums {1, 2, 3};
        assert(3 == sln.rob(nums));
    }
    return 0;
}