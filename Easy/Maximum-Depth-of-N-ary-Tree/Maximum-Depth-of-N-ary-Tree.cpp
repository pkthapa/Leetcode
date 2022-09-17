#include "main.hpp"

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (nullptr == root) {
            return 0;
        }

        int depth = 1;

        for (size_t i = 0; i < root->children.size(); ++i) {
            depth = std::max(depth, 1 + maxDepth(root->children[i]));
        }
        return depth;
    }
};

int main() {
    Solution sln;
    {
        vector<Node*> l2ChildrenOf3 {new Node(5), new Node(6)};
        vector<Node*> l1ChildrenOf1 {new Node(3, l2ChildrenOf3), new Node(2), new Node(4)};

        Node* root = new Node(1, l1ChildrenOf1);

        assert(3 == sln.maxDepth(root));
    }
    {
        vector<Node*> l4ChildrenOf11 {new Node(14)};

        vector<Node*> l3ChildrenOf7 {new Node(11, l4ChildrenOf11)};
        vector<Node*> l3ChildrenOf8 {new Node(12)};
        vector<Node*> l3ChildrenOf9 {new Node(13)};

        vector<Node*> l2ChildrenOf3 {new Node(6), new Node(7, l3ChildrenOf7)};
        vector<Node*> l2ChildrenOf4 {new Node(8, l3ChildrenOf8)};
        vector<Node*> l2ChildrenOf5 {new Node(9, l3ChildrenOf9), new Node(10)};

        vector<Node*> l1Children {new Node(2), new Node(3, l2ChildrenOf3), new Node(4, l2ChildrenOf4), new Node(5, l2ChildrenOf5)};
        Node* root = new Node(1, l1Children);

        assert(5 == sln.maxDepth(root));
    }
    return 0;
}