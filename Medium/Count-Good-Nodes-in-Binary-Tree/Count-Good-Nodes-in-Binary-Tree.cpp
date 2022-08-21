#include "main.hpp"

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int dfs(TreeNode* node, int maxVal) {
        if (nullptr == node) {
            return 0;
        }

        // Check the good node condition.
        int res = (node->val >= maxVal) ? 1 : 0;

        // Store the max node value along the path.
        // We have to pass the maximum node value along the path.
        maxVal = std::max(maxVal, node->val);

        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);

        return res;
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(1);
        root->left->left = new TreeNode(3);
        root->right = new TreeNode(4);
        root->right->left = new TreeNode(1);
        root->right->right = new TreeNode(5);
        assert(4 == sln.goodNodes(root));
    }
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(2);
        assert(3 == sln.goodNodes(root));
    }
    {
        TreeNode* root = new TreeNode(1);
        assert(1 == sln.goodNodes(root));
    }
    return 0;
}