#include "main.hpp"

class Solution {
public:
    bool solve(int index, vector<int>& matchsticks, vector<int>& sides, int sideLen) {
        // If we reach till the length of the array, that means we successfully reached the end.
        // Which means that the input is correctly forming square.
        if (index == matchsticks.size()) {
            return true;
        }

        for (int k = 0; k < 4; k++) {
            if (sides[k] + matchsticks[index] <= sideLen) {
                sides[k] += matchsticks[index];

                // Check for another index of the 'matchsticks' array.
                if (solve(index + 1, matchsticks, sides, sideLen)) {
                    return true;
                }

                // Backtrack.
                sides[k] -= matchsticks[index];
            }
        }
        return 0;    
    }

    bool makesquare(vector<int>& matchsticks) {
        vector<int> sides {0, 0, 0, 0};
        int totalSum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (totalSum % 4 != 0) {
            return false;
        }

        // Shortcut: after sorting, if the first entry is lengthier than a side of the square, then return false.
        sort(matchsticks.begin(), matchsticks.end(), std::greater<>());

        // Start with index 0.
        return solve(0, matchsticks, sides, totalSum / 4);
    }
};

int main() {
    Solution sln;
    {
        vector<int> matchsticks {1, 1, 2, 2, 2};
        assert(true == sln.makesquare(matchsticks));
    }
    {
        vector<int> matchsticks {1, 2, 2, 2};
        assert(false == sln.makesquare(matchsticks));
    }
    {
        vector<int> matchsticks {3, 3, 3, 3};
        assert(true == sln.makesquare(matchsticks));
    }
    return 0;
}