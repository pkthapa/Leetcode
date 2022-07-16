#include "main.hpp"

class Solution {
public:
    int thirdMax(vector<int>&& nums) {
        int64_t firstMax = INT64_MIN;
        int64_t secondMax = INT64_MIN;
        int64_t thirdMax = INT64_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            int64_t temp1 = firstMax, temp2 = secondMax;

            // If duplicate found in any of the max variables, then skip it.
            if (nums[i] == firstMax or nums[i] == secondMax or nums[i] == thirdMax) {
                continue;
            }

            if (nums[i] > firstMax) {
                firstMax = nums[i];
                secondMax = temp1;
                thirdMax = temp2;
            }
            else if (nums[i] > secondMax) {
                secondMax = nums[i];
                thirdMax = temp2;
            }
            else if (nums[i] > thirdMax) {
                thirdMax = nums[i];
            }
        }
        return (thirdMax == INT64_MIN) ? firstMax : thirdMax;
    }
};

int main() {
    Solution sln;

    assert(1 == sln.thirdMax({1, 2, 3}));

    assert(3 == sln.thirdMax({1, 1, 3})); // 1 is twice, so it is skipped. Consider input will be {1, 3}.

    assert(-1 == sln.thirdMax({1, 2, -1}));

    assert(INT32_MIN == sln.thirdMax({1, 2, INT32_MIN}));

    assert(1 == sln.thirdMax({1}));

    return 0;
}