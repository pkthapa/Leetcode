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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool left2Right = true;
        vector<vector<int>> result;
        
        while (!q.empty()) {
            int currLevelSize = q.size();
            vector<int> currLevelNodes(currLevelSize);
            
            for (int i = 0; i < currLevelSize; ++i) {
                auto currNode = q.front();
                q.pop();
                
                // Based on 'left2Right', keep pushing all nodes' value from either left or right.
                if (left2Right) {
                    currLevelNodes[i] = currNode->val;
                }
                else {
                    currLevelNodes[currLevelSize - i - 1] = currNode->val;
                }
                
                // Push left child.
                if (nullptr != currNode->left) {
                    q.push(currNode->left);
                }
                // Push right child.
                if (nullptr != currNode->right) {
                    q.push(currNode->right);
                }
            }
            left2Right = !left2Right;
            result.push_back(currLevelNodes);
        }
        return result;
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

        auto result = sln.zigzagLevelOrder(root);

        assert(3 == result[0][0]);
        assert(20 == result[1][0]);
        assert(9 == result[1][1]);
        assert(15 == result[2][0]);
        assert(7 == result[2][1]);
    }
    return 0;
}