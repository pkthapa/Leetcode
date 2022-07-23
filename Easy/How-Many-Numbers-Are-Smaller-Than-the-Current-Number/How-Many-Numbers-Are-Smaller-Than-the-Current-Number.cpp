#include "main.hpp"

class Solution {
public:
    // Credits: https://www.youtube.com/watch?v=eHqwoWiMDfY
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Phase 1: Lets create an array of size '101' as per one of the constraints.
        // Update this array with the occurence frequency.
        vector<int> occurenceFreq(101);

        for (int i = 0; i < nums.size(); ++i) {
            ++occurenceFreq[nums[i]];
        }

        // Phase 2: Sum the occurence frequency with the previous occurences.
        for (int i = 1; i < 101; ++i) {
            occurenceFreq[i] += occurenceFreq[i - 1];
        }

        // Phase 3: The previous position in 'occurenceFreq' will have the
        // count of smaller numbers than itself.
        for (int i = 0; i < nums.size(); ++i) {
            auto offset = nums[i];
            if (0 == offset) {
                nums[i] = 0; // There is no left index. Out of bound scenario.
            }
            else {
                nums[i] = occurenceFreq[offset - 1];
            }
        }
        return nums;
    }
};

int main() {
    Solution sln;
    {
        vector<int> v {8, 1, 2, 2, 3};
        vector<int> res {4, 0, 1, 1, 3};
        assert(res == sln.smallerNumbersThanCurrent(v));
    }
    {
        vector<int> v {6, 5, 4, 8};
        vector<int> res {2, 1, 0, 3};
        assert(res == sln.smallerNumbersThanCurrent(v));
    }
    {
        vector<int> v {7, 7, 7, 7};
        vector<int> res {0, 0, 0, 0};
        assert(res == sln.smallerNumbersThanCurrent(v));
    }
    return 0;
}