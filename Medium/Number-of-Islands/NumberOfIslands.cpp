#include "main.hpp"

int dx[] {-1,  0, 1, 0};
int dy[] { 0, -1, 0, 1};

class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0'; // Reset to water so that next time this cell is not visited again.
        
        // Need to check for all horizontal and vertical neighbors.
        for (int n{0}; n < 4; ++n){
            int newCell_i = i + dx[n];
            int newCell_j = j + dy[n];

            if ((newCell_i < grid.size() && newCell_i >= 0) &&
                (newCell_j < grid[0].size() && newCell_j >= 0) && 
                (grid[newCell_i][newCell_j] == '1')){

                dfs(grid, newCell_i, newCell_j);
            }
        }
    }
    
public:

    int numIslands(vector<vector<char>>& grid) {
        int islandCount{0};

        for (int i{0}; i < grid.size(); ++i){

            for (int j{0}; j < grid[0].size(); ++j){

                if (grid[i][j] == '1'){ // Land found, so now let's do dfs to find the area.

                    ++islandCount;

                    dfs(grid, i, j);
                }
            }
        }
        return islandCount;
    }
};

int main(int argc, char* argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<vector<char>> grid;

    int row, col, globalCnt;
    char c;
    cin >> globalCnt;

    for (int g = 0; g < globalCnt; ++g){
        cin  >> row >> col;

        for (int i = 0; i < row; ++i){
            vector<char> vc;
            for (int j = 0; j < col; ++j){
                cin >> c;
                vc.push_back(c);
            }
            grid.push_back(vc);
        }

        Solution sln;
        cout << sln.numIslands(grid) << endl;

        grid.clear();
    }
    return 0;
}