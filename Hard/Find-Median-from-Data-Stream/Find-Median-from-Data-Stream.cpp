#include "main.hpp"

class MedianFinder {
    priority_queue<int> smallElementsHeap; // Max Heap.
    priority_queue<int, vector<int>, std::greater<int>> largeElementsHeap; // Min Heap.

public:
    MedianFinder() {}
    
    void addNum(int num) {
        // Always push in small element heap (max heap) whenever we get a new number.
        smallElementsHeap.push(num);
        
        // Check if 'smallElementsHeap' has any number greater than any nums in 'largeElementsHeap'.
        if (!smallElementsHeap.empty() &&
            !largeElementsHeap.empty() &&
            smallElementsHeap.top() > largeElementsHeap.top()) {

            largeElementsHeap.push(smallElementsHeap.top());
            smallElementsHeap.pop();
        }

        int m = smallElementsHeap.size();
        int n = largeElementsHeap.size();

        // Move top element from 'smallElementsHeap' to 'largeElementsHeap'.
        if (m > n + 1) {
            largeElementsHeap.push(smallElementsHeap.top());
            smallElementsHeap.pop();
        }
        
        // Move top element from 'largeElementsHeap' to 'smallElementsHeap'.
        if (n > m + 1) {
            smallElementsHeap.push(largeElementsHeap.top());
            largeElementsHeap.pop();
        }
    }
    
    double findMedian() {
        int m = smallElementsHeap.size();
        int n = largeElementsHeap.size();

        if (m > n) {
            return smallElementsHeap.top();
        }
        if (n > m) {
            return largeElementsHeap.top();
        }
        return static_cast<double>(smallElementsHeap.top() + largeElementsHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    assert(1.5 == obj->findMedian());
    obj->addNum(3);
    assert(2 == obj->findMedian());

    return 0;
}