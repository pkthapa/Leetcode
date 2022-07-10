#include "main.hpp"

class Solution {
public:
    // Explanation: https://www.youtube.com/watch?v=ktmzAZWkEZ0
    int minCostClimbingStairs(vector<int>&& cost) {
        cost.push_back(0);

        for (int i = cost.size() - 3; i >= 0; --i) {
            // Can be written as below line also, just by removing 'cost[i]' because it is common. Notice '+=' operation.
            // cost[i] = min(cost[i] + cost[i + 1], cost[i] + cost[i + 2]);
            cost[i] += std::min(cost[i + 1], cost[i + 2]);
        }
        return std::min(cost[0], cost[1]);
    }
};

int main() {
    Solution sln;

    assert(15 == sln.minCostClimbingStairs({10, 15, 20}));

    assert(6 == sln.minCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}));
    
    assert(10 == sln.minCostClimbingStairs({10, 15}));

    return 0;
}