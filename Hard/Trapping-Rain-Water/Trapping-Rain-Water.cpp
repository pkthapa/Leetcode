#include "main.hpp"

class Solution {
public:
    // Two pointer approach.
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[l];
        int rightMax = height[r];
        int result = 0;

        while (l < r) {
            if (leftMax < rightMax) {
                l += 1;
                leftMax = std::max(leftMax, height[l]);
                result += leftMax - height[l];
            }
            else {
                r -= 1;
                rightMax = std::max(rightMax, height[r]);
                result += rightMax - height[r];
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> height {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        assert(6 == sln.trap(height));
    }
    {
        vector<int> height {4, 2, 0, 3, 2, 5};
        assert(9 == sln.trap(height));
    }
    return 0;
}