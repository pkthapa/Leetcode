#include "main.hpp"

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end)/2;
            
            if (target <= nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return start;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lowerBound(nums, target);
        int idx2 = lowerBound(nums, target + 1) - 1;
        
        if (idx1 < nums.size() && target == nums[idx1]) {
            return {idx1, idx2};
        }
        return {-1, -1};
    }
};

int main() {
    Solution sln;
    {
        int target = 8;
        vector<int> nums {5, 7, 7, 8, 8, 10};
        vector<int> result {3, 4};
        assert(result == sln.searchRange(nums, target));
    }
    {
        int target = 3;
        vector<int> nums {5, 7, 7, 8, 8, 10};
        vector<int> result {-1, -1};
        assert(result == sln.searchRange(nums, target));
    }
    {
        int target = 31;
        vector<int> nums {5, 7, 7, 8, 8, 10};
        vector<int> result {-1, -1};
        assert(result == sln.searchRange(nums, target));
    }
    {
        int target = 3;
        vector<int> nums {3, 3, 3, 3};
        vector<int> result {0, 3};
        assert(result == sln.searchRange(nums, target));
    }
    {
        int target = 3;
        vector<int> nums {};
        vector<int> result {-1, -1};
        assert(result == sln.searchRange(nums, target));
    }
    {
        int target = 1;
        vector<int> nums {1};
        vector<int> result {0, 0};
        assert(result == sln.searchRange(nums, target));
    }
    {
        int target = 10;
        vector<int> nums {1};
        vector<int> result {-1, -1};
        assert(result == sln.searchRange(nums, target));
    }
    return 0;
}