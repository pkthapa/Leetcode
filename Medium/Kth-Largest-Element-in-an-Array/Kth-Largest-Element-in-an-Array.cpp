#include "main.hpp"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap.
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        
        // Store first 'k' nums elements into the minHeap.
        for (int i = 0; i < k; ++i) {
            minHeap.push(nums[i]);
        }
        
        // Now for process remaining elements in nums.
        // Since, the minHeap contains max of 'k' elements only, so
        // the top of minHeap will be our intended result (kth largest element).
        for (int i = k; i < nums.size(); ++i) {
            // While processing remaining elements, if the current element is greater
            // than the top of minHeap then pop the top and insert the current element.
            // This ensures that we are storing kth largest element.
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};

int main() {
    Solution sln;
    {
        int k = 2;
        vector<int> nums {3, 2, 1, 5, 6, 4};
        assert(5 == sln.findKthLargest(nums, k));
    }
    {
        int k = 4;
        vector<int> nums {3, 2, 3, 1, 2, 4, 5, 5, 6};
        assert(4 == sln.findKthLargest(nums, k));
    }
    return 0;
}