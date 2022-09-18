#include "main.hpp"

class Solution {
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            std::swap(nums[l++], nums[r--]);
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int l = 0;
        int r = nums.size() - 1;
        
        if (k > 0) {
            // Reverse whole array.
            // std::reverse(nums.begin(), nums.end());
            reverse(nums, l, r);

            // Reverse the first 'k' elements.
            // std::reverse(nums.begin(), nums.begin() + k);
            reverse(nums, 0, k - 1);

            // Reverse the remaining 'k' elements.
            // std::reverse(nums.begin() + k, nums.end());
            reverse(nums, k, r);
        }
    }
};

int main() {
    Solution sln;
    {
        int k = 3;
        vector<int> nums {1, 2, 3, 4, 5, 6, 7};
        sln.rotate(nums, k);
        vector<int> rotated {5, 6, 7, 1, 2, 3, 4};
        assert(rotated == nums);
    }
    {
        int k = 0;
        vector<int> nums {1, 2, 3, 4, 5, 6, 7};
        sln.rotate(nums, k);
        vector<int> rotated {1, 2, 3, 4, 5, 6, 7};
        assert(rotated == nums);
    }
    {
        int k = 7;
        vector<int> nums {1, 2, 3, 4, 5, 6, 7};
        sln.rotate(nums, k);
        vector<int> rotated {1, 2, 3, 4, 5, 6, 7};
        assert(rotated == nums);
    }
    return 0;
}
