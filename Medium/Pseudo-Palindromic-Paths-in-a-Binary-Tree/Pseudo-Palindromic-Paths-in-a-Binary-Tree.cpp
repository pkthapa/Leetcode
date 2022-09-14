#include "main.hpp"

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// https://www.youtube.com/watch?v=N6YYlQYzsnE&ab_channel=AlgorithmsMadeEasy
class Solution {
    int result = 0;

    bool isPalindrome(const vector<int>& digits) {
        int oddCount = 0;

        for (int i = 1; i <= 9; ++i) {
            // As per hint 1: Note that the node values of a path form a palindrome if at most one digit has an odd frequency (parity).
            if (digits[i] % 2 != 0) {
                ++oddCount;
            }
        }
        return (oddCount > 1) ? false : true;
    }
    
    void dfs(TreeNode* node, vector<int>& digits) {
        if (nullptr == node) {
            return;
        }
        
        ++digits[node->val]; // Increment the occurrence count.
        
        // If leaf node is reached.
        if (nullptr == node->left && nullptr == node->right) {
            if (isPalindrome(digits)) {
                ++result;
            }
        }
        else {
            dfs(node->left, digits);
            dfs(node->right, digits);
        }

        // Backtrack.
        --digits[node->val];
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> digits(10); // Constraint says "1 <= Node.val <= 9". It keeps digits' occurrence count.
        dfs(root, digits);
        return result;
    }
};

int main() {
    {
        Solution sln;
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(3);
        root->left->left = new TreeNode(3);
        root->left->right = new TreeNode(1);

        root->right = new TreeNode(1);
        root->right->right = new TreeNode(1);

        assert(2 == sln.pseudoPalindromicPaths(root));
    }
    {
        Solution sln;
        TreeNode* root = new TreeNode(2);
        root->left = new TreeNode(1);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->left->right->right = new TreeNode(1);

        root->right = new TreeNode(1);

        assert(1 == sln.pseudoPalindromicPaths(root));
    }
    return 0;
}