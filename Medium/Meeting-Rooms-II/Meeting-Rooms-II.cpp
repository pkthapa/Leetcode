#include "main.hpp"

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<int> startTimes(n);
        vector<int> endTimes(n);
        
        for (int i = 0; i < n; ++i) {
            startTimes[i] = intervals[i][0];
            endTimes[i] = intervals[i][1];
        }
        
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        
        int s = 0; // Index for startTimes.
        int e = 0; // Index for endTimes.
        int count = 0; // Keeps current number of rooms required.
        int result = 0; // Keeps maximum number of rooms required till now.
        
        while (s < n) {
            // The idea behind is: we check if a new meeting has started before any meeting ends, then increment 'count'.
            // Otherwise, decrement 'count' and proceed to check for another end time.
            if (startTimes[s] < endTimes[e]) {
                ++count;
                ++s;
            }
            else {
                --count;
                ++e;
            }
            result = std::max(result, count);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> intervals {{0, 30}, {5, 10}, {15, 20}};
        assert(2 == sln.minMeetingRooms(intervals));
    }
    {
        vector<vector<int>> intervals {{7, 10}, {2, 4}};
        assert(1 == sln.minMeetingRooms(intervals));
    }
    {
        vector<vector<int>> intervals {{7, 10}, {2, 8}, {7, 8}};
        assert(3 == sln.minMeetingRooms(intervals));
    }
    return 0;
}