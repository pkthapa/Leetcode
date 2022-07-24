#include "main.hpp"

class Solution {
public:
    vector<int> dx { 0, 0, 1, -1}; // For row.
    vector<int> dy {-1, 1, 0,  0}; // For col.

    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
        // Change the color of the cell to 'newColor' so that we don't visit this cell again.
        image[sr][sc] = newColor;
        
        for (int i = 0; i < 4; ++i) {
            const int newsr = sr + dx[i]; // New row.
            const int newsc = sc + dy[i]; // New col.

            if (newsr < image.size() && newsr >= 0 && newsc < image[0].size() && newsc >= 0 && image[newsr][newsc] == oldColor) {
                dfs(image, newsr, newsc, newColor, oldColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        // Get the color to be replaced.
        const int oldColor = image[sr][sc];

        // If starting pixel is already 'newColor', then no changes to be made.
        if (image[sr][sc] == newColor) {
            return image;
        }

        dfs(image, sr, sc, newColor, oldColor);

        return image;
    }
};

int main() {
    Solution sln;
    {
        int sr = 1, sc = 1, color = 2;
        vector<vector<int>> image  {{1, 1, 1},
                                    {1, 1, 0},
                                    {1, 0, 1}};
        vector<vector<int>> output {{2, 2, 2},
                                    {2, 2, 0},
                                    {2, 0, 1}};
        assert(output == sln.floodFill(image, sr, sc, color));
    }
    {
        int sr = 1, sc = 2, color = 2;
        vector<vector<int>> image  {{1, 1, 1},
                                    {1, 1, 0},
                                    {1, 0, 1}};
        vector<vector<int>> output {{1, 1, 1},
                                    {1, 1, 2},
                                    {1, 0, 1}};
        assert(output == sln.floodFill(image, sr, sc, color));
    }
    {
        int sr = 0, sc = 0, color = 0;
        vector<vector<int>> image  {{0, 0, 0},
                                    {0, 0, 0}};
        vector<vector<int>> output {{0, 0, 0},
                                    {0, 0, 0}};
        assert(output == sln.floodFill(image, sr, sc, color));
    }
    return 0;
}