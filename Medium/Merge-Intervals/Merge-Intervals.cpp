#include "main.hpp"

class Solution {
public:
    // https://www.youtube.com/watch?v=44H3cEC2fFM&ab_channel=NeetCode

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end()); // TC: O(nlogn)
        
        // Load with the first interval to handle edge case.
        vector<vector<int>> output {intervals[0]};
        
        for (int i = 1; i < intervals.size(); ++i) {
            int lastEnd = output.back()[1]; // End time of latest added interval.
            
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart <= lastEnd) {
                // We need max here because what if the first interval ends before
                // second interval. In this case we need to take max of first-interval-end
                // and current-interval-end.
                // [[2, 4] [3, 5]]: In this case we need '5' and not '4'.
                output.back()[1] = std::max(lastEnd, currEnd);
            }
            else {
                output.push_back({currStart, currEnd});
            }
        }
        return output;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> intervals {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        vector<vector<int>> output {{1, 6}, {8, 10}, {15, 18}};
        assert(output == sln.merge(intervals));
    }
    {
        vector<vector<int>> intervals {{1, 4}, {4, 5}};
        vector<vector<int>> output {{1, 5}};
        assert(output == sln.merge(intervals));
    }
    return 0;
}