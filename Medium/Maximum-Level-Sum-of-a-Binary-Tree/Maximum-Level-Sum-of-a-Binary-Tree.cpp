#include "main.hpp"

/**
 * Definition for a binary tree node.
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
    int maxLevelSum(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        
        int level = 0;
        pair<int, int> result({level, INT32_MIN}); // Pair of level and sum.

        queue<TreeNode*> q({root});

        while (!q.empty()) {
            int currLevelSize = q.size();
            int currLevelSum = 0;

            while (currLevelSize-- > 0) {
                auto currNode = q.front();
                q.pop();
            
                currLevelSum += currNode->val;
                
                // Push left child.
                if (nullptr != currNode->left) {
                    q.push(currNode->left);
                }
                
                // Push right child.
                if (nullptr != currNode->right) {
                    q.push(currNode->right);
                }
            }
            level++;

            // If currLevelSum is max then previous max, then update the 'result'.
            if (currLevelSum > result.second) {
                result = {level, currLevelSum};
            }
        }
        return result.first;
    }
};

int main() {
    Solution sln;
    {
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);

        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        assert(2 == sln.maxLevelSum(root));
    }
    {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(7);
        root->left->left = new TreeNode(7);
        root->left->right = new TreeNode(-8);

        root->right = new TreeNode(0);

        assert(2 == sln.maxLevelSum(root));
    }
    return 0;
}