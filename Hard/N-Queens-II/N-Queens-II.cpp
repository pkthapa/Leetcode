#include "main.hpp"

// Reference: https://github.com/pkthapa/Leetcode/blob/main/Hard/N-Queens/N-Queens.cpp
class Solution {
public:
    bool canPlaceQueen(vector<string>& queens, int n, int row, int col) {
        // Check all top cells in same col.
        // Here, 'row' changes from 0 to row, and 'col' is fixed.
        for (int i = 0; i < row; ++i) {
            if (queens[i][col] == 'Q') {
                return false;
            }
        }

        // Check left upper diagonal.
        int i = row;
        int j = col;

        while (i >= 0 and j >= 0) {
            if (queens[i][j] == 'Q') {
                return false;
            }
            --i, --j;
        }

        // Check right upper diagonal.
        i = row;
        j = col;

        while (i >= 0 and j < n) {
            if (queens[i][j] == 'Q') {
                return false;
            }
            --i, ++j;
        }
        return true;
    }

    void nQueens(vector<string>& queens, vector<vector<string>>& result, int row, int n) {
        // Base case.
        if (row == n) {
            result.emplace_back(queens);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (canPlaceQueen(queens, n, row, col)) {
                queens[row][col] = 'Q';

                nQueens(queens, result, row + 1, n);
                
                // Backtrack.
                queens[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> queens(n, string(n, '.'));
        vector<vector<string>> result;

        nQueens(queens, result, 0, n);

        return result.size();
    }
};

int main() {
    Solution sln;

    assert(1 == sln.totalNQueens(1));
    assert(0 == sln.totalNQueens(2));
    assert(0 == sln.totalNQueens(3));
    assert(2 == sln.totalNQueens(4));
    assert(10 == sln.totalNQueens(5));
    assert(4 == sln.totalNQueens(6));
    assert(40 == sln.totalNQueens(7));
    assert(92 == sln.totalNQueens(8));
    assert(352 == sln.totalNQueens(9));
    assert(2680 == sln.totalNQueens(11));

    return 0;
}