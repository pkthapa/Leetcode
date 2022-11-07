#include "main.hpp"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIdx = 0;
        int curr = 0;
        
        while (curr < nums.size()) {
            if (nums[curr] != 0) {
                std::swap(nums[nonZeroIdx++], nums[curr]);
            }
            ++curr;
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
