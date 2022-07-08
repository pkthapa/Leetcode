#include "main.hpp"

class Solution {
public:
    int removeElement(vector<int>&& nums, int val) {
        
        int i = 0, j = 0;
        
        for (; j < nums.size(); ++j){
            if (nums[j] != val){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};

int main() {
    Solution sln;

    assert(2 == sln.removeElement({3, 2, 2, 3}, 2));

    assert(5 == sln.removeElement({0, 1, 2, 2, 3, 0, 4, 2}, 2));

    return 0;
}