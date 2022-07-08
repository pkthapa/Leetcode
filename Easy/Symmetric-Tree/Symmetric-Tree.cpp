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
  //**************************************************
  // Recursive approach.
  //**************************************************
  bool helper(TreeNode* n1, TreeNode* n2){
    if (n1 == nullptr or n2 == nullptr){
      return (n1 == n2);
    }

    if (n1->val != n2->val) return false;
    
    return helper(n1->left, n2->right) and
        helper(n1->right, n2->left);
  }

  bool isSymmetricUsingRecursion(TreeNode* root) {
    if (nullptr == root){
      return true;
    }
    return helper(root->left, root->right);
  }

  //**************************************************
  // Iterative approach.
  //**************************************************
  bool isSymmetricUsingIteration(TreeNode* root) {
    if (nullptr == root) return true;

    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()){
      auto left = q.front();
      q.pop();
      auto right = q.front();
      q.pop();

      if (nullptr == left and nullptr == right){
        continue;
      }
      if ((nullptr == left and nullptr != right) or
          (nullptr != left and nullptr == right)){
        return false;
      }

      if (left->val != right->val){
        return false;
      }

      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    }
    return true;
  }
};

int main() {
  Solution sln;

  TreeNode* root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(2);
  root1->left->left = new TreeNode(3);
  root1->right->right = new TreeNode(3);
  root1->left->right = new TreeNode(4);
  root1->right->left = new TreeNode(4);
  assert(true == sln.isSymmetricUsingRecursion(root1));
  assert(true == sln.isSymmetricUsingIteration(root1));

  TreeNode* root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(2);
  root2->left->right = new TreeNode(3);
  root2->right->right = new TreeNode(3);
  assert(false == sln.isSymmetricUsingRecursion(root2));
  assert(false == sln.isSymmetricUsingIteration(root2));

  TreeNode* root3 = nullptr;
  assert(true == sln.isSymmetricUsingRecursion(root3));
  assert(true == sln.isSymmetricUsingIteration(root3));

  TreeNode* root4 = new TreeNode(1);
  assert(true == sln.isSymmetricUsingRecursion(root4));
  assert(true == sln.isSymmetricUsingIteration(root4));

  return 0;
}