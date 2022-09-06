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
    bool canDelete(TreeNode* node) {
        if (nullptr == node->left && nullptr == node->right && 0 == node->val) {
            return true;
        }
        return false;
    }

public:
    TreeNode* pruneTree(TreeNode* root) {
        if (nullptr == root) {
            return nullptr;
        }

        // Post order traversal technique.
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // Root is processed here after left and right children.
        if (canDelete(root)) {
            delete root;
            return nullptr;
        }
        return root;
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(1);
        root->right = new TreeNode(0);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(1);

        TreeNode* prunedTree = sln.pruneTree(root);

        assert(prunedTree->val == 1);
        assert(prunedTree->right->val == 0);
        assert(prunedTree->right->left == nullptr);
        assert(prunedTree->right->right->val == 1);
    }
    return 0;
}