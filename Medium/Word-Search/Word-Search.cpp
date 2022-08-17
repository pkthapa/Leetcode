#include "main.hpp"

class Solution {
    bool dfs(vector<vector<char>>& board, string& word, int ROWS, int COLS, vector<vector<bool>>& visited, int r, int c, int i) {
        if (word.size() == i) {
            return true; // Word found.
        }

        // Check for boundary cases.
        if (r < 0 || c < 0 ||
            r >= ROWS || c >= COLS ||
            word[i] != board[r][c] ||
            true == visited[r][c]) { // If visited, then return false.
            return false;
        }

        visited[r][c] = true;

        bool result = dfs(board, word, ROWS, COLS, visited, r + 1, c, i + 1) ||
                      dfs(board, word, ROWS, COLS, visited, r - 1, c, i + 1) ||
                      dfs(board, word, ROWS, COLS, visited, r, c + 1, i + 1) ||
                      dfs(board, word, ROWS, COLS, visited, r, c - 1, i + 1);

        // Backtrack.
        visited[r][c] = false;

        return result;
    }

public:
    // Will solve this using DFS approach.
    bool exist(vector<vector<char>>& board, string word) {
        const int ROWS = board.size();
        const int COLS = board[0].size();
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (dfs(board, word, ROWS, COLS, visited, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sln;
    {
        string word = "ABCCED";
        vector<vector<char>> board {{'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}};
        assert(true == sln.exist(board, word));
    }
    {
        string word = "AAAAAAAAAAAABAA";
        vector<vector<char>> board {{'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'},
                                    {'A','A','A','A','A','A'}};
        assert(false == sln.exist(board, word));
    }
    {
        string word = "AAB";
        vector<vector<char>> board {{'C','A','A'},
                                    {'A','A','A'},
                                    {'B','C','D'}};
        assert(true == sln.exist(board, word));
    }
    return 0;
}