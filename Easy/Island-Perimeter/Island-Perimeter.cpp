#include "main.hpp"

// Credits: https://www.youtube.com/watch?v=fISIuAFRM2s&ab_channel=NeetCode
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int row, int col, set<pair<int, int>>& visitedCell) {
        // Base case 1.
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) {
            return 1;
        }
        
        // Base case 2.
        if (visitedCell.find({row, col}) != visitedCell.end()) {
            return 0;
        }

        // Mark as visited.
        visitedCell.insert({row, col});

        int perimeter = dfs(grid, row + 1, col, visitedCell);
        perimeter += dfs(grid, row - 1, col, visitedCell);
        perimeter += dfs(grid, row, col + 1, visitedCell);
        perimeter += dfs(grid, row, col - 1, visitedCell);

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        // Store visited cell info.
        set<pair<int, int>> visitedCell;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                // Find the starting cell.
                if (grid[row][col] == 1) {
                    return dfs(grid, row, col, visitedCell);
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> grid {{0, 1, 0, 0},
                                  {1, 1, 1, 0},
                                  {0, 1, 0, 0},
                                  {1, 1, 0, 0}};
        assert(16 == sln.islandPerimeter(grid));
    }
    {
        vector<vector<int>> grid {{0},
                                  {1}};
        assert(4 == sln.islandPerimeter(grid));
    }
    {
        vector<vector<int>> grid {{0}};
        assert(0 == sln.islandPerimeter(grid));
    }
    {
        vector<vector<int>> grid {{1}};
        assert(4 == sln.islandPerimeter(grid));
    }
    {
        vector<vector<int>> grid {{1, 1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1, 1},
                                  {1, 1, 1, 1, 1, 1}};
        assert(24 == sln.islandPerimeter(grid));
    }
    return 0;
}