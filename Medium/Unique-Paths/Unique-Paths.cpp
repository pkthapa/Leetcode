#include "main.hpp"

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // Initialize the bottom row with 1's.
        vector<int> row (n, 1);
    
        // Iterate for remaining rows 'm - 1',
        // since the last row contains all 1s.
        for (int i = 0; i < m - 1; ++i) {
            vector<int> newRow(n, 1);
            
            for (int j = n - 2; j >= 0; --j) {
                // newRow[j + 1] is always going to be 1, since
                // it is the right-most column.
                // The right-most column and the bottow row is always
                // going to be 1s.
                newRow[j] = newRow[j + 1] + row[j];
            }
            row = newRow;
        }
        return row[0];
    }
};

int main() {
    Solution sln;

    assert(3 == sln.uniquePaths(3, 2));

    assert(28 == sln.uniquePaths(3, 7));

    assert(818809200 == sln.uniquePaths(15, 20));

    return 0;
}