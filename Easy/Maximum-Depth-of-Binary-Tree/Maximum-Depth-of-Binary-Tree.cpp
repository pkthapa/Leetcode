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
    int maxDepth(TreeNode* root) {
        int ld = 0, rd = 0;
        if (nullptr != root){
            ld = maxDepth(root->left) + 1;
            rd = maxDepth(root->right) + 1;
        }
        return (ld > rd) ? ld : rd;
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right = new TreeNode(7);
        root->right->left = new TreeNode(6);
        root->right->right = new TreeNode(9);

        assert(3 == sln.maxDepth(root));
    }
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        assert(3 == sln.maxDepth(root));
    }
    {
        TreeNode* root = new TreeNode(3);

        assert(1 == sln.maxDepth(root));
    }
    return 0;
}