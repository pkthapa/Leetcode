#include "main.hpp"

/**
* @brief Definition for a binary tree node.
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
  TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* curr = root;

    while (nullptr != curr){
      if (curr->val == val){
        return curr;
      }
      if (val < curr->val){ // Go left.
        curr = curr->left;
      }
      else{ // Go right.
        curr = curr->right;
      }
    }
    return {};
  }
};

int main() {
  Solution sln;

  auto newNode1 = new TreeNode(2);
  TreeNode* root1 = new TreeNode(4);
  root1->left = newNode1;
  root1->right = new TreeNode(7);
  root1->left->left = new TreeNode(1);
  root1->left->right = new TreeNode(3);
  assert(newNode1 == sln.searchBST(root1, 2));
  
  auto newNode2 = new TreeNode(3);
  TreeNode* root2 = new TreeNode(4);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(7);
  root2->left->left = new TreeNode(1);
  root2->left->right = newNode2;
  assert(newNode2 == sln.searchBST(root2, 3));

  TreeNode* root3 = nullptr;
  assert(nullptr == sln.searchBST(root3, 10));

  TreeNode* root4 = new TreeNode(1);
  assert(root4 == sln.searchBST(root4, 1));

  return 0;
}