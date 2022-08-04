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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (nullptr == p && nullptr == q) {
            return true;
        }

        if (nullptr != p && nullptr != q && p->val == q->val) {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (nullptr == subRoot) {
            return true;
        }
        // Order matters here:
        // 1. First check the nullness of 'subRoot'.
        // 2. Then check the nullness of 'root'.
        if (nullptr == root) {
            return false;
        }

        // If the 'root' and 'subRoot' does not belong to same tree, then
        // we need to move and check the left and right subtrees of 'root'.
        if (isSameTree(root, subRoot)) {
            return true;
        }
        else {
            return isSubtree(root->left, subRoot) ||
                   isSubtree(root->right, subRoot);
        }
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(4);
        root->right = new TreeNode(5);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(2);

        TreeNode* subRoot = new TreeNode(4);
        subRoot->left = new TreeNode(1);
        subRoot->right = new TreeNode(2);
        
        assert(true == sln.isSubtree(root, subRoot));
    }
    return 0;
}