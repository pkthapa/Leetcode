#include "main.hpp"

class Solution {
public:
    // Lets create a set and store allthe numbers of 'nums' into the set.
    int longestConsecutive(vector<int>& nums) {
        // Set 's' will store the 'nums' in a sorted order.
        set<int> s (nums.begin(), nums.end());
        int longest = 0;

        for (auto num : nums) {
            // If 'num - 1' is not found, that means 'num' is the first
            // number of the series. Now that we have the starting number 'num',
            // we need to keep incrementing 'num + 1' every time and check if
            // it is present in set 's'.
            if (s.count(num - 1) == 0) {
                int len = 0;
                
                while (s.count(num + len) > 0) {
                    ++len; // Increment it, so that we get to find another successive number 'num + len'.
                }
                longest = std::max(longest, len);
            }
        }
        return longest;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {100, 4, 200, 1, 3, 2};
        assert(4 == sln.longestConsecutive(nums));
    }
    {
        vector<int> nums {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        assert(9 == sln.longestConsecutive(nums));
    }
    {
        vector<int> nums {-100, 4, 200, 1, -97, 3, -96, 2, -99, -98};
        assert(5 == sln.longestConsecutive(nums));
    }
    return 0;
}