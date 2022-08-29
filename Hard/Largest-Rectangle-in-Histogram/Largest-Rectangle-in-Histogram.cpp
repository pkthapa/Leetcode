#include "main.hpp"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // pair: {index, height}
        stack<pair<int, int>> stk;
        int result = 0;
        int n = heights.size();

        for (int i = 0; i < n; ++i) {
            int start = i;

            while (!stk.empty() && stk.top().second > heights[i]) {
                int idx = stk.top().first;
                int height = stk.top().second;
                stk.pop();

                int width = i - idx;

                result = std::max(result, height * width);
                start = idx;
            }
            stk.push({start, heights[i]});
        }

        while (!stk.empty()) {
            int width = n - stk.top().first;
            int height = stk.top().second;
            stk.pop();
            
            result = std::max(result, height * width);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> heights {2, 1, 5, 6, 2, 3};
        assert(10 == sln.largestRectangleArea(heights));
    }
    {
        vector<int> heights {2, 4};
        assert(4 == sln.largestRectangleArea(heights));
    }
    {
        vector<int> heights {2, 2, 2, 1};
        assert(6 == sln.largestRectangleArea(heights));
    }
    return 0;
}