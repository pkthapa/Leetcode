#include "main.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int result = nums[l];
        
        while (l <= r) {
            // What if the whole array is sorted.
            // This condition is for un-rotated array.
            if (nums[l] < nums[r]) {
                result = std::min(result, nums[l]);
                break;
            }
            
            int mid = (l + r) / 2;
            result = std::min(result, nums[mid]);

            if (nums[mid] >= nums[l]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {3, 4, 5, 1, 2};
        assert(1 == sln.findMin(nums));
    }
    {
        vector<int> nums {4, 5, 6, 7, 0, 1, 2};
        assert(0 == sln.findMin(nums));
    }
    {
        vector<int> nums {11, 13, 15, 17};
        assert(11 == sln.findMin(nums));
    }
    return 0;
}