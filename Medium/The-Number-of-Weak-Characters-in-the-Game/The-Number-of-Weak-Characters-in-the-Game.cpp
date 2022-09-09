#include "main.hpp"

class Solution {
    static bool comp(const vector<int>& a, const vector<int>& b) {
        // If 0-index values are equal, then sort in decreasing order based on 1-index values.
        // E.g.
        // {6 3}, {6 10}, {6, 2}, then
        // Without 'comp', the sorted result would be {6 2}, {6 3} {6 10}
        // With 'comp' the sorted result will be {6 10} {6 3} {6 2} which is because of 'return a[1] > b[1];' condition.
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        // The idea here is to sort in a group fashion.
        // 1. Sort the input based on attack in a non-decreasing manner, i.e., attack[i] is always <= attack[i + 1]
        // 2. If attack[i] == attack[i + 1], then sort according to 'defense[i] > defense[i + 1]'
        sort(properties.begin(), properties.end(), comp);

        int minTillNow = INT32_MIN;
        int result = 0;
        
        for (int i = properties.size() - 1; i >= 0; --i) {
            if (properties[i][1] < minTillNow) {
                ++result;
            }
            
            minTillNow = std::max(minTillNow, properties[i][1]);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> properties {{5, 5}, {6, 3}, {3, 6}};
        assert(0 == sln.numberOfWeakCharacters(properties));
    }
    {
        vector<vector<int>> properties {{2, 2}, {3, 3}};
        assert(1 == sln.numberOfWeakCharacters(properties));
    }
    {
        vector<vector<int>> properties {{1, 5}, {10, 4}, {4, 3}};
        assert(1 == sln.numberOfWeakCharacters(properties));
    }
    {
        vector<vector<int>> properties {{5, 5}, {6, 3}, {3, 6}, {100, 200}, {100, 100}, {100, 201}};
        assert(3 == sln.numberOfWeakCharacters(properties));
    }
    return 0;
}