#include "main.hpp"

class Solution {
public:
    // https://www.youtube.com/watch?v=UZRkpGk943Q
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if (0 == n1 || 0 == n2) {
            return 0;
        }
        
        // Take the length of row and column to be (n1 + 1) & (n2 + 1) respectively, to keep
        // the calculation for inputs with length '0'.
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        int maxLen = 0;

        // Lets fill the dp array.
        // Skip indices '0' for both row and column, because if any one of the
        // given input is empty, then the longest common substring (max length of repeated subarray)
        // will be anyway '0'.
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    // Add '1' to the upper diagonal position in 'dp'.
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    
                    maxLen = std::max(maxLen, dp[i][j]);
                }
                else {
                    // This step can be skipped (anyway it is initialized to 0).
                    // Just keeping this for understanding.
                    dp[i][j] = 0;
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums1{1, 2, 3, 2, 1};
        vector<int> nums2{3, 2, 1, 4, 7};
        assert(3 == sln.findLength(nums1, nums2));
    }
    {
        vector<int> nums1{0, 0, 0, 0};
        vector<int> nums2{0, 0, 0, 0};
        assert(4 == sln.findLength(nums1, nums2));
    }
    return 0;
}