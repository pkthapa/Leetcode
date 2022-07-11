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
    /**
     * Approach 1: Recursive approach.
     */
    void helper(TreeNode* root, int level, vector<int>& res) {
        if (nullptr == root) {
            return;
        }

        // We check if level matches with the vector size, because we push right node first.
        if (res.size() == level) {
            res.push_back(root->val);
        }

        helper(root->right, level + 1, res);
        helper(root->left, level + 1, res);
    }

    vector<int> rightSideViewRecursive(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }

        vector<int> res;
        helper(root, 0, res);
        return res;
    }

    /**
     * Approach 2: Iterative approach.
     */
    vector<int> rightSideViewIterative(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }

        vector<int> res;
        queue<TreeNode*> q;

        // Push root node first.
        q.push(root);
        
        while (!q.empty()) {
            auto size = q.size(); // Get the queue size.

            // Loop until 'size' becomes 0. When its 0, it indicates the last (right-view) element
            // because we are pushing 'left' and 'right' nodes respectively.
            while (size-- > 0) {
                auto t = q.front();
                q.pop();

                if (0 == size) {
                    res.push_back(t->val);
                }

                if (nullptr != t->left) {
                    q.push(t->left);
                }
                if (nullptr != t->right) {
                    q.push(t->right);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sln;
    {
        vector<int> res {1, 3, 4};
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->right->right = new TreeNode(4);
        root->left->right = new TreeNode(5);
        assert(res == sln.rightSideViewRecursive(root));
        assert(res == sln.rightSideViewIterative(root));
    }
    {
        vector<int> res {1, 3, 4};
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        assert(res == sln.rightSideViewRecursive(root));
        assert(res == sln.rightSideViewIterative(root));
    }
    {
        vector<int> res {1};
        TreeNode* root = new TreeNode(1);
        assert(res == sln.rightSideViewRecursive(root));
        assert(res == sln.rightSideViewIterative(root));
    }
    {
        vector<int> res;
        TreeNode* root = nullptr;
        assert(res == sln.rightSideViewRecursive(root));
        assert(res == sln.rightSideViewIterative(root));
    }

    return 0;
}