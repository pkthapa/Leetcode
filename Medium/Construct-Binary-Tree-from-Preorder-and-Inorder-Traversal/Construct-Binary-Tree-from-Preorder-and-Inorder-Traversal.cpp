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

/**
 * The 'preorder' array guarantees that the first element is always a root element.
 * Traverse 'preorder' array one-by-one and make every element a root element.
 * Now, for a particular root, we can take help of 'inorder' array to decide the left and right subtree.
 * For example:
 *              preorder = [3,9,20,15,7]
 *              inorder = [9,3,15,20,7]
 * 
 * Initially, we are at index 0 of 'preorder' array. Let's make it a root.
 * Now using 'inorder' array, we can find the left subtree and right subtree of 3.
 * i.e.:
 *      left element(s) of 3 in 'inorder' array belongs to left subtree of 3.
 *      right element(s) of 3 in 'inorder' array belongs to right subtree of 3.
 *
 * Move one step ahead in 'preorder' array. Now we are at the 1st index of 'preorder' array.
 * Again, make it a root element and find it's left and right subtree using 'inorder' array.
 *
 * This can be done using recursion.
 */
class Solution {
public:
    TreeNode* helper(int& idx, vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end) {
            return {};
        }

        auto root = new TreeNode(preorder[idx]);

        int mid = -1;
        // Find the index of the root in 'inorder' array so that
        // we can make left subtree and right subtree.
        for (int i = start; i <= end; ++i) {
            if (preorder[idx] == inorder[i]) {
                mid = i;
                break;
            }
        }

        ++idx;
        root->left = helper(idx, preorder, inorder, start, mid - 1);
        root->right = helper(idx, preorder, inorder, mid + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int start = 0;
        int end = preorder.size() - 1;

        return helper(idx, preorder, inorder, start, end);
    }
};

int main() {
    Solution sln;
    {
        vector<int> preorder {3, 9, 20, 15, 7};
        vector<int> inorder {9, 3, 15, 20, 7};

        TreeNode* root = sln.buildTree(preorder, inorder);

        assert(root->val == 3);
        assert(root->left->val == 9);
        assert(root->left->left == nullptr);
        assert(root->left->right == nullptr);
        assert(root->right->val == 20);
        assert(root->right->left->val == 15);
        assert(root->right->right->val == 7);
    }
    {
        vector<int> preorder {-1};
        vector<int> inorder {-1};

        TreeNode* root = sln.buildTree(preorder, inorder);

        assert(root->val == -1);
        assert(root->left == nullptr);
        assert(root->right == nullptr);
    }
    return 0;
}