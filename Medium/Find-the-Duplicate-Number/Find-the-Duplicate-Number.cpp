#include "main.hpp"

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums{1, 3, 4, 2, 2};
        assert(2 == sln.findDuplicate(nums));
    }
    {
        vector<int> nums{3, 1, 3, 4, 2};
        assert(3 == sln.findDuplicate(nums));
    }
    return 0;
}