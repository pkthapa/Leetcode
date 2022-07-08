#include "main.hpp"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // Move all the non-zero numbers to the beginning.
        int i = 0;
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                nums[i++] = nums[j];
            }
        }

        // Update the remaining vector elements with '0'.
        while (i < nums.size()) {
            nums[i++] = 0;
        }
    }
};

int main(int argc, char* argv[]) {
    Solution sln;

    {
        vector<int> v {0, 1, 0, 3, 2};
        vector<int> o {1, 3, 2, 0, 0};
        sln.moveZeroes(v);
        assert(o == v);
    }
    {
        vector<int> v {0};
        vector<int> o {0};
        sln.moveZeroes(v);
        assert(o == v);
    }
    {
        vector<int> v {0, 0, 1, -3, 2};
        vector<int> o {1, -3, 2, 0, 0};
        sln.moveZeroes(v);
        assert(o == v);
    }

    return 0;
}
