#include "main.hpp"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;
        
        // Similar to bucket sort. Works only with 3 different values sorting.
        while (i <= r) {
            // We only swap in case of '0' and '2'.
            if (nums[i] == 0) {
                std::swap(nums[i], nums[l]);
                ++i;
                ++l;
            }
            else if (nums[i] == 2) {
                std::swap(nums[i], nums[r]);
                --r;
            }
            else {
                ++i;
            }
        }
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums{2, 0, 2, 1, 1, 0};
        sln.sortColors(nums);
        assert(nums[0] == 0);
        assert(nums[1] == 0);
        assert(nums[2] == 1);
        assert(nums[3] == 1);
        assert(nums[4] == 2);
        assert(nums[5] == 2);
    }
    return 0;
}