#include "main.hpp"

class Solution {
    static bool myComparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Sorting (in increasing order) on the basis of last-day (end time) of each course.
        sort(courses.begin(), courses.end(), myComparator);
        
        // Max heap to store the included courses.
        priority_queue<int> maxHeap;
        int currTime = 0; // To stipulate if the current course can be completed on time.
        
        for (int i = 0; i < courses.size(); ++i) {
            // duration + currTime <= endTime
            if (courses[i][0] + currTime <= courses[i][1]) {
                
                // Case 1: The course can be completed in time, hence we simply include it
                
                maxHeap.push(courses[i][0]); // Add current course duration to maxHeap.
                currTime += courses[i][0]; // Add current course duration to keep track of total time.
            }
            else if (!maxHeap.empty() && maxHeap.top() > courses[i][0]) {
                
                // Case 2: There is a course already included which is greater than the duration of current course.
                
                currTime -= maxHeap.top() - courses[i][0];
                
                // Pop the highest duration and insert the current duration.
                maxHeap.pop();
                maxHeap.push(courses[i][0]);
            }
        }
        // Since our priority queue contains all the completed courses, we return its size.
        return maxHeap.size();
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> courses {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
        assert(3 == sln.scheduleCourse(courses));
    }
    {
        vector<vector<int>> courses {{1, 2}};
        assert(1 == sln.scheduleCourse(courses));
    }
    {
        vector<vector<int>> courses {{3, 2}, {4, 3}};
        assert(0 == sln.scheduleCourse(courses));
    }
    return 0;
}