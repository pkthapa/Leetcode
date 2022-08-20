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
    pair<bool, int> dfs(TreeNode* root) {
        if (nullptr == root) {
            return {true, 0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        bool balanced = left.first && right.first &&
                        abs(left.second - right.second) <= 1;

        return {balanced, 1 + std::max(left.second, right.second)};
    }

public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};

int main() {
    Solution sln;
    {
        auto root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        assert(true == sln.isBalanced(root));
    }
    {
        auto root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(3);
        root->left->left->left = new TreeNode(4);
        root->left->left->right = new TreeNode(4);
        root->right = new TreeNode(2);
        assert(false == sln.isBalanced(root));
    }
    {
        auto root = nullptr;
        assert(true == sln.isBalanced(root));
    }
    return 0;
}