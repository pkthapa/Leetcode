#include "main.hpp"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    TreeNode* dfs(TreeNode* root) {
        if (nullptr == root) {
            return nullptr;
        }

        auto leftTail = dfs(root->left); // Points to the tail of the left sub-tree.
        auto rightTail = dfs(root->right); // Points to the tail of the right sub-tree.

        // Shift the left sub-tree to right side of the root node.
        if (nullptr != root->left) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        // Since the left-subtree is shifted to right-side of the root node,
        // we will first try to return rightTail, or leftTail (if rightTail is nullptr),
        // or root (if leftTail is nullptr).
        if (nullptr != rightTail) {
            return rightTail;
        }
        else if (nullptr != leftTail) {
            return leftTail;
        }
        else {
            return root;
        }
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(3);

        sln.flatten(root);

        assert(2 == root->val);
        assert(1 == root->right->val);
        assert(3 == root->right->right->val);
        assert(nullptr == root->left);
    }
    {
        TreeNode* root = nullptr;

        sln.flatten(root);

        assert(nullptr == root);
    }
    return 0;
}