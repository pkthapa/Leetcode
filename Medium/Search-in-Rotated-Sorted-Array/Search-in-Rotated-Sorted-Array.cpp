#include "main.hpp"

class Solution {
public:
    // Binary search.
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = (l + r) >> 1; // Mid index.
            
            if (target == nums[mid]) {
                return mid;
            }
            
            // Check if left part of 'mid' or right part of 'mid' is sorted.

            // Left part of 'mid' is sorted.
            if (nums[l] <= nums[mid]) {
                // Check if 'target' is present in sorted left part of 'mid'.
                // If 'target' is not in range of [nums[l].....nums[mid]] both inclusive, then
                // it's time to shift our search to right part by making 'l' point to 'mid + 1'.
                // Visualize this way:
                /*
                |(target)---(nums[l])---(nums[mid])-------(nums[r])|
                */
                if (target < nums[l] or nums[mid] < target) {
                    l = mid + 1;
                }
                // Visualize this way:
                /*
                |(nums[l])---(target)---(nums[mid])-------(nums[r])|
                */
                else {
                    r = mid - 1;
                }
            }
            // Right part of 'mid' is sorted.
            else {
                // If 'target' is out of bound [nums[mid].....nums[r]] both inclusive.
                // Visualize this way:
                /*
                |(nums[l])---(target)---(nums[mid])-------(nums[r])|
                */
                if (target < nums[mid] or nums[r] < target) {
                    r = mid - 1;
                }
                // Visualize this way:
                /*
                |(nums[l])---(nums[mid])---(target)-------(nums[r])|
                */
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