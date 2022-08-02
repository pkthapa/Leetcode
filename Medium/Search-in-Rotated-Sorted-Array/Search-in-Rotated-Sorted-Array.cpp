#include "main.hpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Left sorted portion.
            if (nums[l] <= nums[mid]) {
                if (target > nums[mid] or target < nums[l]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            // Right sorted portion.
            else {
                if (target < nums[mid] or target > nums[r]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sln;
    {
        int target = 0;
        vector<int> nums {4, 5, 6, 7, 0, 1, 2};
        assert(4 == sln.search(nums, target));
    }
    {
        int target = 3;
        vector<int> nums {4, 5, 6, 7, 0, 1, 2};
        assert(-1 == sln.search(nums, target));
    }
    {
        int target = 0;
        vector<int> nums {1};
        assert(-1 == sln.search(nums, target));
    }
    return 0;
}