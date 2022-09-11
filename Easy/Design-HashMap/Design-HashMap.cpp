#include "main.hpp"

class MyHashMap {
    class List {
    public:
        int key;
        int value;
        List* next;
        List(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    List* head = nullptr;

public:
    MyHashMap() {
        head = new List(-1, -1);
    }
    
    void put(int key, int value) {
        auto curr = head;
        auto prev = head;

        while (nullptr != curr) {
            if (key == curr->key) {
                curr->value = value; // Update the existing value.
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = new List(key, value);
    }

    int get(int key) {
        auto curr = head;
        
        while (nullptr != curr) {
            if (curr->key == key) {
                return curr->value; // If 'key' found, then return the value associated with the 'key'.
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        auto curr = head;
        auto prev = head;
        
        while (nullptr != curr) {
            if (curr->key == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap* obj = new MyHashMap();
    obj->put(1, 1);
    obj->put(2, 2);
    assert(1 == obj->get(1));
    assert(-1 == obj->get(3));
    obj->put(2, 1);
    assert(1 == obj->get(2));
    obj->remove(2);
    assert(-1 == obj->get(2));
    return 0;
}