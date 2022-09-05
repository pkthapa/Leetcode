#include "main.hpp"

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Cyclic sort algorithm.
        int i = 0;
        while (i < nums.size()) {
            // Compare the current iterating number 'nums[i]' is equal to the
            // correct offset at 'nums[i]'. If equal, then we increment the
            // current offset.
            if (nums[i] == nums[nums[i] - 1]) {
                ++i;
            }
            else {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 != nums[i]) {
                result.emplace_back(i + 1);
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
        vector<int> result{5, 6};
        assert(result == sln.findDisappearedNumbers(nums));
    }
    {
        vector<int> nums{1, 1};
        vector<int> result{2};
        assert(result == sln.findDisappearedNumbers(nums));
    }
    {
        vector<int> nums{2, 4, 1, 2};
        vector<int> result{3};
        assert(result == sln.findDisappearedNumbers(nums));
    }
    return 0;
}