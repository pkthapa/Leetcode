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
    vector<double> averageOfLevels(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }
        
        vector<double> result;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            auto size = q.size();

            auto count {0};
            double sum = 0.0;

            while (size-- > 0) {
                auto node = q.front();
                q.pop();

                ++count;
                sum += node->val;

                if (nullptr != node->left) {
                    q.push(node->left);
                }
                if (nullptr != node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(sum/count);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<double> res {3.00000, 14.50000, 11.00000};
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);
        assert(res == sln.averageOfLevels(root));
    }
    {
        vector<double> res {3.00000, 14.50000, 11.00000};
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->left->left = new TreeNode(15);
        root->left->right = new TreeNode(7);
        assert(res == sln.averageOfLevels(root));
    }
    {
        vector<double> res {1.00000};
        TreeNode* root = new TreeNode(1);
        assert(res == sln.averageOfLevels(root));
    }
    return 0;
}