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
    void helper(TreeNode* root, vector<int>& v){
        if (nullptr != root){
            helper(root->left, v);

            v.push_back(root->val);

            helper(root->right, v);
        }
    }

    // 1st approach.
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;

        helper(root, v);
        return v;
    }

    // 2nd approach.
    vector<int> inorderTraversalUsingStack(TreeNode* root){
        vector<int> v;
        stack<TreeNode*> stk;

        while (root || !stk.empty()){
            
            // Process all the left children first because it is inorder traversal.
            // Pushing 'root' node into the stack ensures it to be processed at the last after completing left children processing.
            while (root){
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();

            v.push_back(root->val);

            // Process right children after processing left and root.
            root = root->right;
        }
        return v;
    }
};

int main() {
    string s;
    Solution sln;

    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    auto v = sln.inorderTraversal(root);
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;

    v = sln.inorderTraversalUsingStack(root);
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}