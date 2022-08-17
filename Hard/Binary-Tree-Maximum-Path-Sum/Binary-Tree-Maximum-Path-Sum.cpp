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
    int dfs(TreeNode* root, int& sum) {
        if (nullptr == root) {
            return 0;
        }

        auto leftSum = std::max(dfs(root->left, sum), 0);
        auto rightSum = std::max(dfs(root->right, sum), 0);

        int currSum = root->val + leftSum + rightSum;
        sum = std::max(sum, currSum);

        return root->val + std::max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int sum = INT32_MIN;
        dfs(root, sum);
        return sum;
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        assert(6 == sln.maxPathSum(root));
    }
    {
        TreeNode* root = new TreeNode(-10);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        assert(42 == sln.maxPathSum(root));
    }
    return 0;
}