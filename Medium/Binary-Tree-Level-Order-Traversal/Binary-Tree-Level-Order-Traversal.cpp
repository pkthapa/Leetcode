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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        while (!q.empty()) {
            // Get the size of the queue.
            auto size = q.size();

            vector<int> v;
            
            // Loop until size is 0. This will loop all the elements of one level only.
            while (size-- > 0) {
                auto node = q.front();
                q.pop();
                v.push_back(node->val);

                // Push left node first.
                if (nullptr != node->left) {
                    q.push(node->left);
                }
                
                // Push right node after pushing left node, if any.
                if (nullptr != node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> res {{3}, {9, 20}, {15, 7}};
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        assert(res == sln.levelOrder(root));
    }
    {
        vector<vector<int>> res {};
        TreeNode* root = nullptr;
        assert(res == sln.levelOrder(root));
    }
    {
        vector<vector<int>> res {{1}};
        TreeNode* root = new TreeNode(1);
        assert(res == sln.levelOrder(root));
    }
    return 0;
}