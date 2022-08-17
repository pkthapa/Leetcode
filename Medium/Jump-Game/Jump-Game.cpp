#include "main.hpp"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goalPost = nums.size() - 1;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i + nums[i] >= goalPost) {
                goalPost = i; // Shift the goalPost to left (nearer to start point).
            }
        }

        // If goalPost is 0, it means that we reached the start offset.
        return (0 == goalPost) ? true : false;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {2, 3, 1, 1, 4};
        assert(true == sln.canJump(nums));
    }
    {
        vector<int> nums {3, 2, 1, 0, 4};
        assert(false == sln.canJump(nums));
    }
    {
        vector<int> nums {1};
        assert(true == sln.canJump(nums));
    }
    return 0;
}