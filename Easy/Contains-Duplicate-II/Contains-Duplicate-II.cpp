#include "main.hpp"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>&& nums, int k) {
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); ++i) {
            auto itr = m.find(nums[i]);
            if (itr != m.end() && i - itr->second <= k) {
                return true;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return false;
    }
};

int main() {
    Solution sln;

    assert(false == sln.containsNearbyDuplicate({1, 0, 1, 1}, 0));

    assert(true == sln.containsNearbyDuplicate({1, 2, 3, 1}, 3));

    assert(false == sln.containsNearbyDuplicate({1, 2, 3, 1, 2, 3}, 2));

    assert(true == sln.containsNearbyDuplicate({1, 0, 1, 1}, 1));

    return 0;
}