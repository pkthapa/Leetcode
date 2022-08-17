#include "main.hpp"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        constexpr int boardSize = 9;
        bool row[boardSize][boardSize] = {false};
        bool col[boardSize][boardSize] = {false};
        bool subarea[boardSize][boardSize] = {false};

        for (int r = 0; r < boardSize; ++r) {
            for (int c = 0; c < boardSize; ++c) {
                // If not number, the pass.
                if (board[r][c] == '.') {
                    continue;
                }

                // Mapping char to number, and then number with index.
                int idx = board[r][c] - '0' - 1;

                // Gives the offset/location of the sub-area.
                int subAreaPos = ((r/3) * 3) + c/3;

                if (row[r][idx] || col[c][idx] || subarea[subAreaPos][idx]) {
                    return false;
                }
                
                row[r][idx] = true;
                col[c][idx] = true;
                subarea[subAreaPos][idx] = true;
            }
        }
        return true;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<char>> board 
           {{'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}};
        assert(true == sln.isValidSudoku(board));
    }
    {
        vector<vector<char>> board 
           {{'8','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}};
        assert(false == sln.isValidSudoku(board));
    }
    return 0;
}