#include "main.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS (nums.size(), 1);

        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] < nums[j]) {
                    LIS[i] = std::max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Return the max element from the vector.
        return *max_element(LIS.begin(), LIS.end());
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {10, 9, 2, 5, 3, 7, 101, 18};
        assert(4 == sln.lengthOfLIS(nums));
    }
    {
        vector<int> nums {0, 1, 0, 3, 2, 3};
        assert(4 == sln.lengthOfLIS(nums));
    }
    {
        vector<int> nums {7, 7, 7, 7, 7};
        assert(1 == sln.lengthOfLIS(nums));
    }
    return 0;
}