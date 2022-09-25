#include "main.hpp"

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Reference: https://www.youtube.com/watch?v=RXy5RzGF5wo&ab_channel=NeetCode

class BSTIterator {
    stack<TreeNode*> stk;
    
public:
    // The idea is to add all left children to stack until left child not found in one down-way.
    // So, this means the root node is at the bottom of the stack.
    BSTIterator(TreeNode* root) {
        while (nullptr != root) {
            stk.push(root);
            root = root->left;
        }
    }
    
    // Get the top element. Check if the popped node has right child.
    // If right child is present, then add all left children of that right child until left child not found in one down-way.
    // For example, for every pop operation, check if the popped node has right child, and then add all left children of
    // the popped node.
    int next() {
        auto t = stk.top();

        int val = t->val;
        stk.pop();
        
        t = t->right; // Go towards right child.
        
        // If right child is present, then add only left children of that right child.
        while (nullptr != t) {
            stk.push(t);
            t = t->left;
        }
        return val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* obj = new BSTIterator(root);
    assert(3 == obj->next());
    assert(7 == obj->next());
    assert(true == obj->hasNext());
    assert(9 == obj->next());
    assert(true == obj->hasNext());
    assert(15 == obj->next());
    assert(true == obj->hasNext());
    assert(20 == obj->next());
    assert(false == obj->hasNext());
    return 0;
}