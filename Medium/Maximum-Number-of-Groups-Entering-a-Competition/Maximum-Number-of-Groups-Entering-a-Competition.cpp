#include "main.hpp"

class Solution {
public:
    int maximumGroups(vector<int>&& grades) {
        sort(grades.begin(), grades.end());
        
        int groupCount = 0;
        int people = 0, total = 0; // Store previous group data.
        int currPeople = 0, currTotal = 0;
        
        for (auto grade : grades) {
            ++currPeople;
            currTotal += grade;
            
            // Check if people in current group is greater than people in previous group.
            if (currPeople > people && currTotal > total) {
                groupCount += 1;
                people = currPeople;
                total = currTotal;
                currPeople = currTotal = 0;
            }
        }
        return groupCount;
    }
};

int main()
{
    Solution sln;

    assert(3 == sln.maximumGroups({10, 6, 12, 7, 3, 5}));

    assert(1 == sln.maximumGroups({8, 8}));

    assert(5 == sln.maximumGroups({2, 31, 41, 31, 36, 46, 33, 45, 47, 8, 31, 6, 12, 12, 15, 35}));

    assert(4 == sln.maximumGroups({16, 30, 12, 36, 4, 26, 23, 25, 19, 26, 30, 32}));

    return 0;
}