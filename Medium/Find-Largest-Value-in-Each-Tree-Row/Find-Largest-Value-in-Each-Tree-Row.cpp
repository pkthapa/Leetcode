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
    vector<int> largestValues(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }

        queue<TreeNode*> q({root});
        vector<int> result;

        while (!q.empty()) {
            int n = q.size();
            int largest = INT32_MIN;

            while (n-- > 0) {
                auto curr = q.front();
                q.pop();

                largest = std::max(largest, curr->val);

                // Add left child to queue.
                if (nullptr != curr->left) {
                    q.push(curr->left);
                }

                // Add right child to queue.
                if (nullptr != curr->right) {
                    q.push(curr->right);
                }
            }
            result.emplace_back(largest);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> res {1, 3, 9};
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(5);
        root->left->right = new TreeNode(3);
        root->right->right = new TreeNode(9);

        assert(res == sln.largestValues(root));
    }
    {
        vector<int> res {1, 3};
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        assert(res == sln.largestValues(root));
    }
    return 0;
}