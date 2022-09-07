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
    string tree2str(TreeNode* root) {
        string str = to_string(root->val);
        
        if (nullptr != root->left) {
            str += "(" + tree2str(root->left) + ")";
        }
        
        if (nullptr != root->right) {
            if (nullptr == root->left) {
                str += "()"; // If left is not present, but right is present.
            }
            str += "(" + tree2str(root->right) + ")";
        }
        return str;
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(4);
        root->right = new TreeNode(3);

        assert("1(2(4))(3)" == sln.tree2str(root));
    }
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->right = new TreeNode(3);

        assert("1(2()(4))(3)" == sln.tree2str(root));
    }
    return 0;
}