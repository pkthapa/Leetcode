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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (nullptr == p and nullptr == q){
            return true;
        }

        if ((nullptr != p and nullptr == q) or (nullptr == p and nullptr != q)){
            return false;
        }

        if (p->val == q->val){
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        }
        return false;
    }
};

int main() {
    Solution sln;
    {
        TreeNode* p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);

        TreeNode* q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(3);

        assert(true == sln.isSameTree(p, q));
    }
    {
        TreeNode* p = new TreeNode(1);
        p->left = new TreeNode(2);

        TreeNode* q = new TreeNode(1);
        q->right = new TreeNode(2);

        assert(false == sln.isSameTree(p, q));
    }
    {
        TreeNode* p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(1);

        TreeNode* q = new TreeNode(1);
        q->left = new TreeNode(1);
        q->right = new TreeNode(2);

        assert(false == sln.isSameTree(p, q));
    }
    {
        TreeNode* p = new TreeNode(1);
        p->left = new TreeNode(2);
        p->right = new TreeNode(3);

        TreeNode* q = new TreeNode(1);
        q->left = new TreeNode(2);
        q->right = new TreeNode(4);

        assert(false == sln.isSameTree(p, q));
    }
    return 0;
}
