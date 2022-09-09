#include "main.hpp"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k > 0) {
            int n = nums.size();
            k %= n;
            
            // Reverse the first 'n - k' numbers.
            reverse(nums.begin(), nums.begin() + n - k);
            
            // Reverse the remaining 'n - k' numbers.
            reverse(nums.begin() + n - k, nums.end());
            
            // Reverse the whole array.
            reverse(nums.begin(), nums.end());
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