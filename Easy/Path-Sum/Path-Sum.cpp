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
    bool dfs(TreeNode* node, int ts, int currSum) {
        if (nullptr == node) {
            return false;
        }

        currSum += node->val;

        // If leaf node.
        if (nullptr == node->left && nullptr == node->right) {
            return (ts == currSum);
        }
        
        return dfs(node->left, ts, currSum) ||
               dfs(node->right, ts, currSum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, 0);
    }
};

int main() {
    {
        int targetSum = 22;

        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(4);
        root->left->left = new TreeNode(11);
        root->left->left->left = new TreeNode(7);
        root->left->left->right = new TreeNode(2);
        root->right = new TreeNode(8);
        root->right->left = new TreeNode(13);

        assert(true == Solution().hasPathSum(root, targetSum));
    }
    {
        int targetSum = 5;

        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        assert(false == Solution().hasPathSum(root, targetSum));
    }
    {
        int targetSum = 5;

        TreeNode* root = nullptr;

        assert(false == Solution().hasPathSum(root, targetSum));
    }
    return 0;
}