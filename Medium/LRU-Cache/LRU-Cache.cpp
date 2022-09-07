#include "main.hpp"

class LRUCache {
    class Node { // Doubly linked list.
    public:
        int key;
        int val;
        Node *prev = nullptr, *next = nullptr;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    // For ease of use.
    Node* head = new Node(-1, -1); // head->next will always point to last recently used.
    Node* tail = new Node(-1, -1); // tail->prev will always point to least recently used.

    int maxCapacity;
    unordered_map<int, Node*> m;

    // Helper functions.
    void deleteNode(Node* node) {
        // Link before deleting the node.
        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;
    }
    
    void addNode(Node* node) {
        auto temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }
    
public:
    LRUCache(int capacity) {
        maxCapacity = capacity;

        // Link the doubly linked list.
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* node2Delete = m[key];

            auto newNode = new Node(key, node2Delete->val);

            deleteNode(node2Delete);
            addNode(newNode);

            m[key] = newNode; // Overwrite the existing key, if present already.

            return newNode->val;
        }
        return -1;
    }

    void put(int key, int value) {
        // Check if the key exist.
        auto itr = m.find(key);
        if (m.end() != itr) {
            auto node = itr->second;
            m.erase(itr);
            deleteNode(node);
        }

        if (m.size() == maxCapacity) {
            // Delete the least recently used and insert the new key-value pair.
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // New node to be added.
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    {
        LRUCache* obj = new LRUCache(2);
        obj->put(1, 1);
        obj->put(2, 2);
        assert(1 == obj->get(1));
        obj->put(3, 3);
        assert(-1 == obj->get(2));
        obj->put(4, 4);
        assert(-1 == obj->get(1));
        assert(3 == obj->get(3));
        assert(4 == obj->get(4));
    }
    {
        LRUCache* obj = new LRUCache(2);
        obj->put(1, 1);
        obj->put(2, 2);
        assert(1 == obj->get(1));
        obj->put(2, 20);
        assert(20 == obj->get(2));
    }
    return 0;
}