#include "main.hpp"

class MyHashSet {
    class List {
    public:
        int key;
        List* next;
        List(int k) : key(k), next(nullptr) {}
    };
    
    List* head = nullptr;
    
public:
    MyHashSet() {
        head = new List(-1);
    }
    
    void add(int key) {
        auto temp = head;
        auto prev = head;

        while (nullptr != temp) {
            if (temp->key == key) {
                // Key already present, so do not add.
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        prev->next = new List(key);
    }
    
    void remove(int key) {
        auto temp = head;
        List* prev = head;
        
        while (nullptr != temp) {
            if (temp->key == key) {
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    
    bool contains(int key) {
        auto temp = head;
        
        while (nullptr != temp) {
            if (temp->key == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main() {
    MyHashSet* obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    assert(true == obj->contains(1));
    assert(false == obj->contains(3));
    obj->add(2);
    assert(true == obj->contains(2));
    obj->remove(2);
    assert(false == obj->contains(2));
    return 0;
}