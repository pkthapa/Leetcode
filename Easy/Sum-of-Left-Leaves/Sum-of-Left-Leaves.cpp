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
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int sum {0};
        if ((nullptr != root->left) and
            (nullptr == root->left->left) and
            (nullptr == root->left->right))
        {
            sum += root->left->val;
        }

        sum += helper(root->left);
        sum += helper(root->right);
        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root);
    }
};

int main() {
    Solution sln;

    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->left->left = new TreeNode(10);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        assert(25 == sln.sumOfLeftLeaves(root)); // (10 + 15)
    }

    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        assert(24 == sln.sumOfLeftLeaves(root)); // (9 + 15)
    }

    {
        TreeNode* root = new TreeNode(3);

        assert(0 == sln.sumOfLeftLeaves(root));
    }

    {
        TreeNode* root = nullptr;

        assert(0 == sln.sumOfLeftLeaves(root));
    }
    return 0;
}