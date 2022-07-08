#include "main.hpp"

class Solution {
public:
    bool containsDuplicate(vector<int>&& nums) {
        unordered_map<int, int> m;

        for (auto i : nums) {
            if (++m[i] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sln;

    assert(true == sln.containsDuplicate({3, 2, 2, 3}));

    assert(false == sln.containsDuplicate({1, 2, 3, 4}));

    assert(true == sln.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}));

    return 0;
}