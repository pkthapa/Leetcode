#include "main.hpp"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() - 1;
        int n = grid[0].size() - 1;
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Step 1: Fill the bottom row first.
        // Step 2: Fill the right-most column.
        // Step 3: Fill rest of the 'dp' cells with formula: dp(i, j) = grid(i, j) + min(dp(i + 1, j), dp(i, j + 1))
        
        // Copy the right-most down cell.
        dp[m][n] = grid[m][n];
        
        // Fill the lowest row first.
        for (int i = n; i > 0; --i) {
            dp[m][i - 1] = dp[m][i] + grid[m][i - 1];
        }
        
        // Fill the right-most column.
        for (int i = m; i > 0; --i) {
            dp[i - 1][n] = dp[i][n] + grid[i - 1][n];
        }
        
        // Fill remaining cells.
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = grid[i][j] + std::min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};

int main() {
    {
        vector<vector<int>> grid {{1, 3, 4, 8},
                                  {3, 2, 2, 4},
                                  {5, 7, 1, 9},
                                  {2, 3, 2, 3}};
        assert(14 == Solution().minPathSum(grid));
    }
    {
        vector<vector<int>> grid {{1, 3, 1},
                                  {1, 5, 1},
                                  {4, 2, 1}};
        assert(7 == Solution().minPathSum(grid));
    }
    {
        vector<vector<int>> grid {{1, 2, 3},
                                  {4, 5, 6}};
        assert(12 == Solution().minPathSum(grid));
    }
    return 0;
}