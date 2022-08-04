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
    void inorder(TreeNode* root, vector<int>& vec) {
        if (nullptr == root) {
            return;
        }
        inorder(root->left, vec);
        vec.emplace_back(root->val);
        inorder(root->right, vec);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        
        // Inorder traversal gives sorted array as output in BST.
        inorder(root, vec);
        
        return vec[k - 1];
    }
};

int main() {
    Solution sln;
    {
        int k = 1;
        auto root = new TreeNode(3);
        root->left = new TreeNode(1);
        root->left->right = new TreeNode(2);
        root->right = new TreeNode(4);

        assert(1 == sln.kthSmallest(root, k));
    }
    {
        int k = 3;
        auto root = new TreeNode(5);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(2);
        root->left->right = new TreeNode(4);
        root->left->left->left = new TreeNode(1);
        root->right = new TreeNode(6);

        assert(3 == sln.kthSmallest(root, k));
    }
    {
        int k = 2;
        auto root = new TreeNode(3);
        root->left = new TreeNode(2);
        root->right = new TreeNode(4);

        assert(3 == sln.kthSmallest(root, k));
    }
    return 0;
}