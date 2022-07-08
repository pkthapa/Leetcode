#include "main.hpp"

class Solution {
public:
    int singleNumber(vector<int>&& nums) {
        int ans {0};

        // We know for sure that each element only appears once or twice.
        // So there is no point of using unordered_map to store the frequency of occurrence.
        // There is one way to do this: XOR operation.
        /* XOR operation.
         * 0 ^ 0 = 0
         * 0 ^ 1 = 1
         * 1 ^ 0 = 1
         * 1 ^ 1 = 0
         */
        for (int i = 0; i < nums.size(); ++i) {
            ans ^= nums[i];
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    Solution sln;

    assert(1 == sln.singleNumber({2, 2, 1}));

    assert(4 == sln.singleNumber({4, 1, 2, 1, 2}));

    assert(1 == sln.singleNumber({1}));

    return 0;
}
