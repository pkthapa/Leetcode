#include "main.hpp"

class Solution {
public:
    /**
     * @brief Approach 1: Using formula: (n (n + 1))/2
     * 'n' is the size of the input vector.
     */
    int missingNumber(vector<int>&& nums) {
        int size = nums.size();
        int expectedSum = (size * (size + 1)) / 2;

        int total {0};
        for (auto i : nums) {
            total += i;
        }
        
        return expectedSum - total;
    }
};

int main(int argc, char* argv[]) {
    Solution sln;

    assert(2 == sln.missingNumber({3, 0, 1}));

    assert(0 == sln.missingNumber({4, 1, 2, 3}));

    assert(8 == sln.missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1}));

    return 0;
}
