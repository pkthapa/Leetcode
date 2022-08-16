#include "main.hpp"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r)/2;
            
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {-1, 0, 3, 5, 9, 12};
        assert(4 == sln.search(nums, 9));
    }
    {
        vector<int> nums {-1, 0, 3, 5, 9, 12};
        assert(-1 == sln.search(nums, 2));
    }
    {
        vector<int> nums {0};
        assert(0 == sln.search(nums, 0));
    }
    {
        vector<int> nums {0};
        assert(-1 == sln.search(nums, 1));
    }
    return 0;
}