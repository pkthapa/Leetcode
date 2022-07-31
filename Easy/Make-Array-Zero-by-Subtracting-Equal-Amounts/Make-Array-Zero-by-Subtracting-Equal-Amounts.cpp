#include "main.hpp"

class Solution {
public:
    // Trick:
    // For example: [1,5,0,3,5]
    // The minimum operations is equal to the count of
    // distint non-zero +ve numbers (excluding repetition).
    // We can use 'set' for this purpose.
    int minimumOperations(vector<int>&& nums) {
        unordered_set<int> s;
        
        for (auto num : nums) {
            if (num > 0) {
                s.insert(num);
            }
        }
        return s.size();
    }
};

int main()
{
    Solution sln;

    assert(3 == sln.minimumOperations({1, 5, 0, 3, 5}));

    assert(1 == sln.minimumOperations({1, 1}));

    assert(0 == sln.minimumOperations({0}));

    return 0;
}