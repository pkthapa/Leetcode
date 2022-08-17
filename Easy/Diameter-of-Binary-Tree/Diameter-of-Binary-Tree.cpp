#include "main.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int dfs(TreeNode* root, int& result) {
        if (nullptr == root) {
            return 0;
        }

        auto left = dfs(root->left, result);
        auto right = dfs(root->right, result);

        // Get the diameter from left and right sub-trees and
        // check if the sum of left and right is greater than previously
        // stored subtree's diameter.
        result = std::max(result, left + right);
        return 1 + std::max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right = new TreeNode(3);
        assert(3 == sln.diameterOfBinaryTree(root));
    }
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        assert(1 == sln.diameterOfBinaryTree(root));
    }
    return 0;
}