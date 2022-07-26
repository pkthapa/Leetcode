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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

int main() {
    Solution sln;

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    auto invertedRoot = sln.invertTree(root);

    assert(invertedRoot->val == 4);
    assert(invertedRoot->left->val == 7);
    assert(invertedRoot->left->left->val == 9);
    assert(invertedRoot->left->right->val == 6);

    assert(invertedRoot->right->val == 2);
    assert(invertedRoot->right->left->val == 3);
    assert(invertedRoot->right->right->val == 1);

    return 0;
}