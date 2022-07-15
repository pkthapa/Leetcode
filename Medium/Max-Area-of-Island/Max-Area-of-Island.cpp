#include "main.hpp"

class Solution {
public:
    int tempArea = 0; // Holds continous count of cells with '1'.

    void dfs(vector<vector<int>>& grid, int i, int j, int* dx, int* dy) {
        grid[i][j] = 0; // Reset to water so that it does not visit this cell again.
        ++tempArea;

        for (int k = 0; k < 4; ++k) {
            int newCell_i = i + dx[k];
            int newCell_j = j + dy[k];
            
            if ((newCell_i < grid.size() and newCell_i >= 0) and
                (newCell_j < grid[0].size() and newCell_j >= 0) and
                (grid[newCell_i][newCell_j] == 1)) {

                dfs(grid, newCell_i, newCell_j, dx, dy);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int maxArea = 0;

        // Need to check for all horizontal and vertical neighbors.
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) { // If land found.
                    dfs(grid, i, j, dx, dy);

                    maxArea = std::max(maxArea, tempArea); // Get the max.
                    tempArea = 0; // Reset to get the next continous count again.
                }
            }
        }
        return maxArea;
    }
};

int main(int argc, char* argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<int>> grid;

    int row, col, globalCnt;
    int c;
    cin >> globalCnt;

    for (int g = 0; g < globalCnt; ++g){
        cin  >> row >> col;

        for (int i = 0; i < row; ++i){
            vector<int> vc;
            for (int j = 0; j < col; ++j){
                cin >> c;
                vc.push_back(c);
            }
            grid.push_back(vc);
        }

        Solution sln;
        cout << sln.maxAreaOfIsland(grid) << endl;

        grid.clear();
    }
    return 0;
}