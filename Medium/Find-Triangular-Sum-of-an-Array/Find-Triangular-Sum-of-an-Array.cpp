#include "main.hpp"

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        const int SUPER_SIZE = nums.size();

        for (int i = 0; i < SUPER_SIZE; ++i) {
            auto newNumsSize = nums.size() - 1;
            vector<int> newNums (newNumsSize);
            
            for (int j = 0; j < newNumsSize; ++j) {
                newNums[j] = (nums[j] + nums[j + 1]) % 10;
            }
            nums = newNums;
        }
        return nums[0];
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums{1, 2, 3, 4, 5};
        assert(8 == sln.triangularSum(nums));
    }
    {
        vector<int> nums{5};
        assert(5 == sln.triangularSum(nums));
    }
    {
        vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert(4 == sln.triangularSum(nums));
    }
    {
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert(0 == sln.triangularSum(nums));
    }
    return 0;
}