#include "main.hpp"

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
  TreeNode* helper(vector<int>& nums, int start, int end){
    if (start > end){
      return nullptr;
    }

    auto mid = (start + end)/2;

    auto root = new TreeNode(nums[mid]);
    root->left = helper(nums, start, mid - 1);
    root->right = helper(nums, mid + 1, end);

    return root;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
};

void inorderTraverseToVerify(TreeNode* n, vector<int>& v){
  if (nullptr != n){
    inorderTraverseToVerify(n->left, v);
    v.push_back(n->val);
    inorderTraverseToVerify(n->right, v);
  }
}

int main() {
  Solution sln;

  {
    vector<int> v{-10,-3,0,5,9}, out;
    auto root = sln.sortedArrayToBST(v);

    inorderTraverseToVerify(root, out);
    assert(out == v);
  }
  {
    vector<int> v{1, 3}, out;
    auto root = sln.sortedArrayToBST(v);

    inorderTraverseToVerify(root, out);
    assert(out == v);
  }

  return 0;
}