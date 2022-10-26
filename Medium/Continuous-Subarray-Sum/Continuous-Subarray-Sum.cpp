#include "main.hpp"

// https://www.youtube.com/watch?v=OKcrLfR-8mE
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // <remainder, index>
        unordered_map<int, int> mp {{0, -1}}; // Initialize for corner case.
        
        // Corner case example.
        // nums = [23,2,4,6,6], k = 7
        
        int total = 0;
        int remainder = 0;
        
        // TC: O(n)
        // Logic: Let's say we have, nums = [20,2,4,6,7], k = 6
        // 20 % 6 = 2
        // (20 + 2) % 6 = 4
        // (20 + 2 + 4) % 6 = 2
        // Which means: (20 + multiples of 6) % 6 will be always same.
        // Since, index is also stored, we can easily find out if atleast 2-nums are processed.
        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];
            remainder = total % k;
            
            if (mp.find(remainder) == mp.end()) {
                mp[remainder] = i;
            }
            else if (i - mp[remainder] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sln;
    {
        int k = 6;
        vector<int> nums {23, 2, 4, 6, 7};
        assert(true == sln.checkSubarraySum(nums, k));
    }
    {
        int k = 6;
        vector<int> nums {23, 2, 6, 4, 7};
        assert(true == sln.checkSubarraySum(nums, k));
    }
    {
        int k = 13;
        vector<int> nums {23, 2, 6, 4, 7};
        assert(false == sln.checkSubarraySum(nums, k));
    }
    {
        int k = 7;
        vector<int> nums {23, 2, 4, 6, 6};
        assert(true == sln.checkSubarraySum(nums, k));
    }
    return 0;
}