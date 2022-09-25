#include "main.hpp"

// Front of the queue is extracted from 'dummyRight->prev' node.
// Back of the queue is extracted from 'dummyLeft->next' node.

class MyCircularDeque {
    struct DLL { // Doubly-linked list.
        int val;
        DLL *next, *prev;
        DLL(int v) : val(v), next(nullptr), prev(nullptr) {}
    };

    // Approach:
    // 1. Insertion will be done on 'dummyLeft->next'.
    // 2. Deletion will be done on 'dummyRight->prev'.
    // i.e. 'dummyRight->prev' node is the oldest node in the list.
    
    // For ease of handling corner cases.
    DLL* dummyLeft;
    DLL* dummyRight;
    
    int size;
    int maxSize;

public:
    MyCircularDeque(int k) {
        size = 0;
        maxSize = k;
        
        dummyLeft = new DLL(-1);
        dummyRight = new DLL(-1);
        
        // Link dummy nodes.
        dummyLeft->next = dummyRight;
        dummyRight->prev = dummyLeft;
    }
    
    bool insertFront(int value) {
        if (!isFull()) {
            ++size;

            auto newNode = new DLL(value);
            
            newNode->prev = dummyRight->prev;
            newNode->next = dummyRight;
            
            dummyRight->prev->next = newNode;
            dummyRight->prev = newNode;
            
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
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
    
    bool deleteFront() {
        if (!isEmpty()) {
            --size;
            
            auto temp = dummyRight->prev;
            
            temp->prev->next = dummyRight;
            dummyRight->prev = temp->prev;
            
            delete temp;
            
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (!isEmpty()) {
            --size;
            
            auto temp = dummyLeft->next;
            
            dummyLeft->next = temp->next;
            temp->next->prev = dummyLeft;
            
            delete temp;
            
            return true;
        }
        return false;
    }
    
    int getFront() {
        if (!isEmpty()) {
            return dummyRight->prev->val;
        }
        return -1;
    }
    
    int getRear() {
        if (!isEmpty()) {
            return dummyLeft->next->val;
        }
        return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
    int k = 3;
    MyCircularDeque* obj = new MyCircularDeque(k);
    assert(true == obj->insertLast(1));
    assert(true == obj->insertLast(2));
    assert(true == obj->insertFront(3));
    assert(false == obj->insertFront(4));
    assert(2 == obj->getRear());
    assert(true == obj->isFull());
    assert(true == obj->deleteLast());
    assert(true == obj->insertFront(4));
    assert(4 == obj->getFront());
    return 0;
}