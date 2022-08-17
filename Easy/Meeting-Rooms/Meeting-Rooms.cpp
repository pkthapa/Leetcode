#include "main.hpp"

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return true;
        }

        sort(intervals.begin(), intervals.end());
        
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> intervals {{0, 30}, {5, 10}, {15, 20}};
        assert(false == sln.canAttendMeetings(intervals));
    }
    {
        vector<vector<int>> intervals {{7, 10}, {2, 4}};
        assert(true == sln.canAttendMeetings(intervals));
    }
    return 0;
}