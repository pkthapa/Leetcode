#include "main.hpp"

class MyCircularQueue {
    struct DLL { // Doubly-linked list.
        int val;
        DLL* next;
        DLL* prev;
        DLL (int v) : val(v), next(nullptr), prev(nullptr) {}
    };
    
    // Stores the current size of DLL excluding dummy nodes.
    int size;
    int maxSize;
    
    // Dummy nodes (makes easier to handle edge cases).
    DLL* dummyLeft;
    DLL* dummyRight;
    
public:
    // Approach:
    // 1. Always add new node at the position left of 'dummyRight' node. 'Front()' is always dummyRight->prev.
    // 2. Delete node from the position right of 'dummyLeft' node. 'Rear()' is always dummyLeft->next.
    MyCircularQueue(int k) {
        dummyLeft = new DLL(-1);
        dummyRight = new DLL(-1);

        dummyLeft->next = dummyRight;
        dummyRight->prev = dummyLeft;
        
        size = 0;
        maxSize = k;
    }
    
    bool enQueue(int value) {
        if (!isFull()) {
            ++size;

            auto newNode = new DLL(value);

            newNode->prev = dummyLeft;
            newNode->next = dummyLeft->next;
            
            dummyLeft->next->prev = newNode;
            dummyLeft->next = newNode;

            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (!isEmpty()) {
            --size;
            
            auto temp = dummyRight->prev;
            
            dummyRight->prev = dummyRight->prev->prev;
            dummyRight->prev->next = dummyRight;
            
            delete temp;
            
            return true;
        }
        return false;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return dummyRight->prev->val;
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return dummyLeft->next->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    int k = 3;
    MyCircularQueue* obj = new MyCircularQueue(k);
    assert(true == obj->enQueue(1));
    assert(true == obj->enQueue(2));
    assert(true == obj->enQueue(3));
    assert(false == obj->enQueue(4));
    assert(3 == obj->Rear());
    assert(true == obj->isFull());
    assert(true == obj->deQueue());
    assert(true == obj->enQueue(4));
    assert(4 == obj->Rear());
    assert(true == obj->deQueue());
    assert(true == obj->deQueue());
    assert(true == obj->deQueue());
    assert(false == obj->deQueue());
    return 0;
}