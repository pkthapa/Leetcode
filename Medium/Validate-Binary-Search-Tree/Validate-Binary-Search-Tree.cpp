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
    bool helper(TreeNode* root, int64_t minimum, int64_t maximum) {
        if (nullptr == root) {
            return true;
        }

        if ((root->val <= minimum) or
            (root->val >= maximum)) {
            return false;
        }
        return (helper(root->left, minimum, root->val) and
                helper(root->right, root->val, maximum));
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, INT64_MIN, INT64_MAX);
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->right = new TreeNode(3);
        assert(true == sln.isValidBST(root));
    }
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(1);
        root->right = new TreeNode(4);
        root->right->left = new TreeNode(3);
        root->right->right = new TreeNode(6);
        assert(false == sln.isValidBST(root));
    }
    {
        TreeNode* root = nullptr;
        assert(true == sln.isValidBST(root));
    }
    return 0;
}