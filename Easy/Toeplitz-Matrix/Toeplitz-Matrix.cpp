#include "main.hpp"

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i + 1 < r && j + 1 < c && // Check overflow conditions.
                    matrix[i][j] != matrix[i + 1][j + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> matrix {{1, 2, 3, 4},
                                    {5, 1, 2, 3},
                                    {9, 5, 1, 2}};
        assert(true == sln.isToeplitzMatrix(matrix));
    }
    {
        vector<vector<int>> matrix {{1, 2},
                                    {2, 2}};
        assert(false == sln.isToeplitzMatrix(matrix));
    }
    return 0;
}