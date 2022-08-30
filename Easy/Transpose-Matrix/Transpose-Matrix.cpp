#include "main.hpp"

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        const int ROW = matrix.size();
        const int COL = matrix[0].size();

        vector<vector<int>> result(COL, vector<int>(ROW));

        for (int i = 0; i < ROW; ++i) {

            for (int j = 0; j < COL; ++j) {

                result[j][i] = matrix[i][j]; // Storing logic.
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> matrix {{1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9}};
        vector<vector<int>> transpose {{1, 4, 7},
                                       {2, 5, 8},
                                       {3, 6, 9}};
        assert(transpose == sln.transpose(matrix));
    }
    {
        vector<vector<int>> matrix {{1, 2, 3},
                                    {4, 5, 6}};
        vector<vector<int>> transpose {{1, 4},
                                       {2, 5},
                                       {3, 6}};
        assert(transpose == sln.transpose(matrix));
    }
    {
        vector<vector<int>> matrix {{1}};
        vector<vector<int>> transpose {{1}};
        assert(transpose == sln.transpose(matrix));
    }
    return 0;
}