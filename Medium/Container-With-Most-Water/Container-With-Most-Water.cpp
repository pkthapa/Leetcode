#include "main.hpp"

// Credits: https://www.youtube.com/watch?v=UuiTKBwPgAo&ab_channel=NeetCode
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            // Take the minimum height pillar from left and right pillars.
            int minHeight = std::min(height[left], height[right]);
            
            // Get the area formed by minimum height pillar with
            // the distance between left and right pillars.
            int area = minHeight * (right - left);
            result = std::max(result, area);

            // Move the pointer away from the minimum height pillar.
            if (height[left] < height[right]) {
                ++left;
            }
            else {
                --right;
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
        assert(49 == sln.maxArea(height));
    }
    {
        vector<int> height{1, 8, 6, 2, 5, 4, 8, 9, 7};
        assert(49 == sln.maxArea(height));
    }
    {
        vector<int> height{1, 50, 51, 2, 5, 4, 8, 3, 7};
        assert(50 == sln.maxArea(height));
    }
    {
        vector<int> height{1, 1};
        assert(1 == sln.maxArea(height));
    }
    {
        vector<int> height{1, 2, 3, 4};
        assert(4 == sln.maxArea(height));
    }
    return 0;
}