#include "main.hpp"

class FrontMiddleBackQueue {
    struct DLL {
        int val;
        DLL *next, *prev;
        DLL(int v) : val(v), next(nullptr), prev(nullptr) {}
    };
    
    // Dummy nodes for ease of handling corner cases.
    // Pushing back will be done on 'dummyLeft->next'.
    // Pushing front will be done on 'dummyRight->prev'.
    // Popping back will be done on 'dummyLeft->next'.
    // Popping front will be done on 'dummyRight->prev'.
    // NOTE: We will consider 'dummyLeft' as rear/back node, and 'dummyRight' as front node.
    
    DLL* dummyLeft;
    DLL* dummyRight;
    
    int size;
    
public:
    FrontMiddleBackQueue() {
        dummyLeft = new DLL(-1);
        dummyRight = new DLL(-1);
        
        // Link dummy nodes.
        dummyLeft->next = dummyRight;
        dummyRight->prev = dummyLeft;
        
        size = 0;
    }
    
    void pushFront(int val) {
        ++size;
        
        auto newNode = new DLL(val);
        
        newNode->next = dummyRight;
        newNode->prev = dummyRight->prev;
        
        dummyRight->prev->next = newNode;
        dummyRight->prev = newNode;
    }
    
    void pushMiddle(int val) {
        int pos = (size / 2);

        auto newNode = new DLL(val);
        auto temp = dummyRight->prev;
        
        while (pos-- > 0) {
            temp = temp->prev;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;
        
        temp->next->prev = newNode;
        temp->next = newNode;
        
        ++size;
    }
    
    void pushBack(int val) {
        ++size;
        
        auto newNode = new DLL(val);
        
        newNode->prev = dummyLeft;
        newNode->next = dummyLeft->next;
        
        dummyLeft->next->prev = newNode;
        dummyLeft->next = newNode;
    }
    
    int popFront() {
        if (0 == size) {
            return -1;
        }
        --size;
        auto temp = dummyRight->prev;
        
        temp->prev->next = dummyRight;
        dummyRight->prev = temp->prev;
        
        int v = temp->val;
        delete temp;
        return v;
    }
    
    int popMiddle() {
        if (0 == size) {
            return -1;
        }

        int pos = (size / 2);
        auto temp = dummyLeft->next;
        --size;
        
        while (pos-- > 0) {
            temp = temp->next;
        }
        
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        
        int v = temp->val;
        delete temp;
        return v;
    }
    
    int popBack() {
        if (0 == size) {
            return -1;
        }
        --size;

        auto temp = dummyLeft->next;
        
        dummyLeft->next = temp->next;
        temp->next->prev = dummyLeft;
        
        int v = temp->val;
        delete temp;
        return v;
    }
};

int main() {
    FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
    obj->pushFront(1);
    obj->pushBack(2);
    obj->pushMiddle(3);
    obj->pushMiddle(4);
    assert(1 == obj->popFront());
    assert(3 == obj->popMiddle());
    assert(4 == obj->popMiddle());
    assert(2 == obj->popBack());
    assert(-1 == obj->popFront());
    return 0;
}