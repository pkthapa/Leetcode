#include "main.hpp"

class Solution {
    bool canPlaceQueen(vector<string>& nQueens, int n, int row, int col) {
        // Check all row cells vertical to a 'col'.
        // Here, 'col' is fixed and 'row' changes from '0' to 'row'.
        for (int i = 0; i < row; ++i) {
            if (nQueens[i][col] == 'Q') {
                return false;
            }
        }

        // Check left diagonal.
        int i = row;
        int j = col;
        while (i >= 0 and j >= 0) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
            --i, --j;
        }

        // Check right diagonal.
        i = row;
        j = col;
        while (i >= 0 and j < n) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
            --i, ++j;
        }
        return true;
    }

    void nQueen(vector<vector<string>>& result, vector<string>& nQueens, int row, int n) {
        // Base case.
        if (row == n) {
            result.emplace_back(nQueens);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (canPlaceQueen(nQueens, n, row, col))
            {
                nQueens[row][col] = 'Q';
                nQueen(result, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        // Init the internal vector with string filled with '.' n times.
        vector<string> nQueens(n, string(n, '.'));
        vector<vector<string>> result;

        nQueen(result, nQueens, 0, n);
        return result;
    }
};

int main() {
    Solution sln;
    {
        constexpr int n = 4;
        auto result = sln.solveNQueens(n);

        assert(2 == result.size());

        assert(result[0][0] == ".Q..");
        assert(result[0][1] == "...Q");
        assert(result[0][2] == "Q...");
        assert(result[0][3] == "..Q.");

        assert(result[1][0] == "..Q.");
        assert(result[1][1] == "Q...");
        assert(result[1][2] == "...Q");
        assert(result[1][3] == ".Q..");
    }
    {
        constexpr int n = 3;
        auto result = sln.solveNQueens(n);

        assert(0 == result.size());
    }
    return 0;
}