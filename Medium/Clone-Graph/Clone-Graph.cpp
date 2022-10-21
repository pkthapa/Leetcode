#include "main.hpp"

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // To store old node and new node (clone).
        unordered_map<Node*, Node*> mapping;
        
        if (nullptr == node) {
            return {};
        }
        
        Node* copy = new Node(node->val);
        
        // Store the old & clone node mapping.
        mapping[node] = copy;
        
        // BFS traversing: visit every node and check if the node's and node-children's clone is made.
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (int i = 0; i < curr->neighbors.size(); ++i) {
                Node* neighbor = curr->neighbors[i];
                
                // If 'neighbor's clone is not created, then create and insert into 'mapping'.
                if (mapping.find(neighbor) == mapping.end()) {
                    mapping[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                
                mapping[curr]->neighbors.push_back(mapping[neighbor]);
            }
        }
        return copy;
    }
};

Node* buildGraph() {
    /*
    1 -- 2
    .    .
    .    .
    4 -- 3
    */
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(new Node(2));
    node1->neighbors.push_back(new Node(4));

    node2->neighbors.push_back(new Node(1));
    node2->neighbors.push_back(new Node(3));

    node3->neighbors.push_back(new Node(2));
    node3->neighbors.push_back(new Node(4));

    node4->neighbors.push_back(new Node(1));
    node4->neighbors.push_back(new Node(3));

    return node1;
}

int main() {
    Solution sln;
    auto original = buildGraph();
    auto copy = sln.cloneGraph(original);

    assert(copy->val == original->val);
    assert(copy != original);

    assert(copy->neighbors[0]->val == original->neighbors[0]->val);
    assert(copy->neighbors[0] != original->neighbors[0]);

    assert(copy->neighbors[1]->val == original->neighbors[1]->val);
    assert(copy->neighbors[1] != original->neighbors[1]);

    return 0;
}