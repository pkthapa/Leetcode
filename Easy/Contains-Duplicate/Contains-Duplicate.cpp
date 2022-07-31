#include "main.hpp"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;

        for (auto i : nums) {
            if (us.count(i) > 0) {
                return true;
            }
            us.insert(i);
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
