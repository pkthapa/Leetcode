#include "main.hpp"

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        for (auto num : nums) {
            int temp = std::max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {1, 2, 3, 1};
        assert(4 == sln.rob(nums));
    }
    {
        vector<int> nums {2, 7, 9, 3, 1};
        assert(12 == sln.rob(nums));
    }
    return 0;
}