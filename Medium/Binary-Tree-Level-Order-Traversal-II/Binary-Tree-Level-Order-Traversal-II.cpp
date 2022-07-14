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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }

        vector<vector<int>> result;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            auto size = q.size();

            vector<int> v;
            while (size-- > 0) {
                auto node = q.front();
                q.pop();

                v.push_back(node->val);

                if (nullptr != node->left) {
                    q.push(node->left);
                }
                if (nullptr != node->right) {
                    q.push(node->right);
                }
            }

            // While inserting, do insert at the first place.
            // Do not use 'push_back()'.
            result.insert(result.begin(), v);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> res {{15, 7}, {9, 20}, {3}};
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        assert(res == sln.levelOrderBottom(root));
    }
    {
        vector<vector<int>> res {};
        TreeNode* root = nullptr;
        assert(res == sln.levelOrderBottom(root));
    }
    {
        vector<vector<int>> res {{1}};
        TreeNode* root = new TreeNode(1);
        assert(res == sln.levelOrderBottom(root));
    }
    return 0;
}