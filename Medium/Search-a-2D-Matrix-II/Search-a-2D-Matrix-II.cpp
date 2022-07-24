#include "main.hpp"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        int maxRow = matrix.size() - 1;

        while (row <= maxRow && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }

            // Begin the search from top-right corner.
            // Since the matrix is sorted in non-decreasing way, so,
            // if target is less than current cell, then decrease column only, else
            // if target is greater than current cell, then increase row only.
            if (target < matrix[row][col]) {
                --col;
            }
            else {
                ++row;
            }
        }
        return false;
    }
};

int main() {
    Solution sln;
    {
        int target = 5;
        vector<vector<int>> matrix {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
        assert(true == sln.searchMatrix(matrix, target));
    }
    {
        int target = 30;
        vector<vector<int>> matrix {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
        assert(true == sln.searchMatrix(matrix, target));
    }
    {
        int target = 20;
        vector<vector<int>> matrix {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
        assert(false == sln.searchMatrix(matrix, target));
    }
    {
        int target = 2;
        vector<vector<int>> matrix {{-1, -1}};
        assert(false == sln.searchMatrix(matrix, target));
    }
    return 0;
}