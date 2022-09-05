#include "main.hpp"

/**
* @brief Definition for a n-ary tree node.
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
    vector<vector<int>> levelOrder(Node* root) {
        if (nullptr == root) {
            return {};
        }

        queue<Node*> q;
        vector<int> temp;
        vector<vector<int>> result;
        
        q.push(root);
        while (!q.empty()) {
            temp.clear();

            int n = q.size();
            while (n-- > 0) {
                auto node = q.front();
                q.pop();

                temp.emplace_back(node->val);

                // Push all the n-children of 'node'.
                for (auto child : node->children) {
                    q.push(child);
                }
            }
            result.emplace_back(temp);
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<vector<int>> res {{1}, {3, 2, 4}, {5, 6}};
        Node* t1 = new Node(3);

        Node* root = new Node(1);
        root->children.emplace_back(t1);
        root->children.emplace_back(new Node(2));
        root->children.emplace_back(new Node(4));

        t1->children.emplace_back(new Node(5));
        t1->children.emplace_back(new Node(6));

        assert(res == sln.levelOrder(root));
    }
    {
        vector<vector<int>> res {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}};
        Node* t01 = new Node(3);
        Node* t02 = new Node(4);
        Node* t03 = new Node(5);

        Node* t11 = new Node(7);
        Node* t12 = new Node(8);
        Node* t13 = new Node(9);

        Node* t21 = new Node(11);

        Node* root = new Node(1);
        root->children.emplace_back(new Node(2));
        root->children.emplace_back(t01);
        root->children.emplace_back(t02);
        root->children.emplace_back(t03);

        t01->children.emplace_back(new Node(6));
        t01->children.emplace_back(t11);
        t02->children.emplace_back(t12);
        t03->children.emplace_back(t13);
        t03->children.emplace_back(new Node(10));

        t11->children.emplace_back(t21);
        t12->children.emplace_back(new Node(12));
        t13->children.emplace_back(new Node(13));

        t21->children.emplace_back(new Node(14));

        assert(res == sln.levelOrder(root));
    }
    return 0;
}