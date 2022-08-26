#include "main.hpp"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> output(n, 0); // Initialize with all zeros.

        // pair<day, temp>
        stack<pair<int, int>> stk;

        for (int i = 0; i < n; ++i) {
            int currDay = i;
            int currTemp = temperatures[i];

            // If the top of the stack has lower temperature.
            while (!stk.empty() && stk.top().second < currTemp) {
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;

                stk.pop();

                output[prevDay] = currDay - prevDay;
            }

            // If currTemp is lower than previous day temp, then push into stack.
            stk.push({currDay, currTemp});
        }
        return output;
    }
};

int main() {
    Solution sln;
    {
        vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
        vector<int> answer{1, 1, 4, 2, 1, 1, 0, 0};
        assert(answer == sln.dailyTemperatures(temperatures));
    }
    {
        vector<int> temperatures{30, 40, 50, 60};
        vector<int> answer{1, 1, 1, 0};
        assert(answer == sln.dailyTemperatures(temperatures));
    }
    {
        vector<int> temperatures{30, 60, 90};
        vector<int> answer{1, 1, 0};
        assert(answer == sln.dailyTemperatures(temperatures));
    }
    return 0;
}