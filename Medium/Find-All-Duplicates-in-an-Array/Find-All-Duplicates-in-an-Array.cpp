#include "main.hpp"

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Logic: This works only for +ve nums (as per constraints).
            // The logic works on the basis of twice negation. If a number appears twice then 2 times negation
            // results in +ve number.
            // So, if a number is found +ve, then add the number is the result set.
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];

            if (nums[abs(nums[i]) - 1] > 0) {
                result.push_back(abs(nums[i]));
            }
        }
        return result;
    }

    /*// Cyclic sort.
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else {
                ++i;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                result.push_back(nums[i]);
            }
        }
        return result;
    }*/
};

int main() {
    Solution sln;
    {
        vector<int> nums {4, 3, 2, 7, 8, 2, 3, 1};
        vector<int> result {2, 3};
        assert(result == sln.findDuplicates(nums));
    }
    {
        vector<int> nums {1, 1, 2};
        vector<int> result {1};
        assert(result == sln.findDuplicates(nums));
    }
    {
        vector<int> nums {1};
        vector<int> result {};
        assert(result == sln.findDuplicates(nums));
    }
    return 0;
}