#include "main.hpp"

/**
* @brief Definition for a binary tree node.
*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int64_t ans = INT64_MAX;
    int64_t min1 = 0;

    void dfs(TreeNode* root) {
        if (nullptr != root) {
            if (min1 < root->val && root->val < ans) {
                ans = root->val;
            }
            // Do dfs only if first minimum is equal to the current root value.
            // We do this to ensure that the dfs call is done only after first minimum.
            else if (min1 == root->val) {
                dfs(root->left);
                dfs(root->right);
            }
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        min1 = root->val; // Store the first minimum.
        
        // Now the 2nd minimum will be between min1 and next max.
        dfs(root);

        return (ans < INT64_MAX) ? ans : -1;
    }
};

int main() {
    {
        Solution sln;
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(2);
        root->right = new TreeNode(5);
        root->right->left = new TreeNode(5);
        root->right->right = new TreeNode(7);
        assert(5 == sln.findSecondMinimumValue(root));
    }
    {
        Solution sln;
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(2);
        root->right = new TreeNode(2);
        assert(-1 == sln.findSecondMinimumValue(root));
    }
    return 0;
}