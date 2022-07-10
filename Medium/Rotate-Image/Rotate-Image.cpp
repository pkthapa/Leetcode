#include "main.hpp"

class Solution {
public:
    // In-place approach.
    void rotateInplace(vector<vector<int>>& matrix) {
        // 1. Transpose the matrix.
        // 2. Reverse each row.

        // Transpose the matrix.
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row.
        for (int i = 0; i < matrix.size(); ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    // Using extra space.
    void rotate(vector<vector<int>>& matrix) {
        vector<int> v;
        vector<vector<int>> res;
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = matrix.size(); j > 0; --j) {
                v.push_back(matrix[j - 1][i]);
            }
            res.push_back(v);
            v.clear();
        }
        matrix = res;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> v {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        vector<vector<int>> res {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
        sln.rotate(v);
        assert(v == res);
    }
    {
        vector<vector<int>> v {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
        vector<vector<int>> res {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
        sln.rotate(v);
        assert(v == res);
    }
    {
        vector<vector<int>> v {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        vector<vector<int>> res {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
        sln.rotateInplace(v);
        assert(v == res);
    }
    {
        vector<vector<int>> v {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
        vector<vector<int>> res {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
        sln.rotateInplace(v);
        assert(v == res);
    }
    return 0;
}