#include "main.hpp"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the starting cell has an obstacle, then simply return as there would be
        // no paths to the destination.
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        // Number of ways to reach the starting cell.
        obstacleGrid[0][0] = 1;
        
        // Filling the values of first column.
        for (int i = 1; i < m; ++i) {
            // Think:
            // You are at (i, 0) and want to update with either '0' or '1'.
            // If the previous column has '1' that means there was no obstacle.
            // If it had '0' that means there was an obstacle (1) and which is now (0).
            // 0 indicates there is no valid path to proceed.
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        }
        
        // Filling the values of first row.
        for (int i = 1; i < n; ++i) {
            // Think: same explanation as above.
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
        }
        
        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
                else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        
        // Return value stored in rightmost bottommost cell. That is the destination.
        return obstacleGrid[m - 1][n - 1];
    }
};

int main() {
    {
        vector<vector<int>> grid {{0, 0, 0},
                                  {0, 1, 0},
                                  {0, 0, 0}};
        assert(2 == Solution().uniquePathsWithObstacles(grid));
    }
    {
        vector<vector<int>> grid {{0, 1},
                                  {0, 0}};
        assert(1 == Solution().uniquePathsWithObstacles(grid));
    }
    {
        vector<vector<int>> grid {{0, 0},
                                  {1, 1},
                                  {0, 0}};
        assert(0 == Solution().uniquePathsWithObstacles(grid));
    }
    return 0;
}