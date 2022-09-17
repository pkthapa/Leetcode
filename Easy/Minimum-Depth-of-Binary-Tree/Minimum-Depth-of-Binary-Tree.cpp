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
    int depth = INT32_MAX;

    void dfs(TreeNode* root, int currDepth) {
        if (nullptr == root) {
            return;
        }

        // Update the minimum depth when leaf node is hit.
        if (nullptr == root->left && nullptr == root->right) {
            depth = std::min(depth, currDepth);
        }

        dfs(root->left, currDepth + 1);
        dfs(root->right, currDepth + 1);
    }

public:
    int minDepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        dfs(root, 1);
        return depth;
    }
};

int main() {
    {
        Solution sln;
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        assert(2 == sln.minDepth(root));
    }
    {
        Solution sln;
        TreeNode* root = new TreeNode(2);
        root->right = new TreeNode(3);
        root->right->right = new TreeNode(4);
        root->right->right->right = new TreeNode(5);
        root->right->right->right->right = new TreeNode(6);

        assert(5 == sln.minDepth(root));
    }
    return 0;
}