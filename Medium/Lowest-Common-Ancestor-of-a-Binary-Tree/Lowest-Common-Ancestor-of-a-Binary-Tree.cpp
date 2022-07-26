#include "main.hpp"

/**
* @brief Definition for a binary tree node.
*/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (nullptr == root || root == p || root == q) {
            return root;
        }

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if (nullptr != left && nullptr != right) {
            return root;
        }
        return (nullptr != left) ? left : right;
    }
};

int main() {
    Solution sln;

    auto lca = new TreeNode(6);
    auto p = new TreeNode(2);
    auto q = new TreeNode(8);
    auto q1 = new TreeNode(5);

    TreeNode* root = lca;
    root->left = p;
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = q1;

    root->right = q;
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    assert(lca == sln.lowestCommonAncestor(root, p, q));
    assert(p == sln.lowestCommonAncestor(root, p, q1));

  return 0;
}