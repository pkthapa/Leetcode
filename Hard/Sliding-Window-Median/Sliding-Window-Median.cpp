#include "main.hpp"

class Solution {
    // Create a priority_queue with remove function.
    template<typename T,
             typename Container = vector<T>,
             typename Comp = std::less<typename Container::value_type>> // std::less creates a max-heap.
    class priority_queue_with_remove : public priority_queue<T, Container, Comp> {
    public:
        bool remove(T& valueToRemove) {
            auto itr = std::find(this->c.begin(), this->c.end(), valueToRemove);
            if (this->c.end() == itr) {
                // Value not found.
                return false;
            }
            this->c.erase(itr);
            
            // Heapify after removing.
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        }
    };

    priority_queue_with_remove<int> maxHeap; // Stores smaller elements only.
    priority_queue_with_remove<int, vector<int>, std::greater<int>> minHeap; // Stores greater elements only.

    // Balances heaps if any one of their sizes is greater than +2 of each other.
    // Example, if maxHeap contains 2 more elements than minHeap then balance them by exchanging the element.
    void rebalanceHeaps() {
        int m = maxHeap.size();
        int n = minHeap.size();

        if (m > n + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (n > m + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

public:

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result (nums.size() - k + 1);

        for (int i = 0; i < nums.size(); ++i) {
            // Always push into max heap 'maxHeap'.
            maxHeap.push(nums[i]);

            if (!maxHeap.empty() &&
                !minHeap.empty() &&
                minHeap.top() < maxHeap.top()) {

                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }

            rebalanceHeaps();

            // Window count reached?
            if (i - k + 1 >= 0) {
                // Add the median to the 'result' array.

                if (maxHeap.size() == minHeap.size()) {
                    // If both the sizes are equal, that means we have even number of elements.
                    // Take the average of the middle two elements.
                    result[i - k + 1] = static_cast<double>((maxHeap.top() / 2.0) + (minHeap.top() / 2.0));
                }
                else if (maxHeap.size() > minHeap.size()) {
                    result[i - k + 1] = static_cast<double>(maxHeap.top());
                }
                else {
                    result[i - k + 1] = static_cast<double>(minHeap.top());
                }

                // Now we have to remove the element going out of the sliding window.
                int elementToRemove = nums[i - k + 1];
                if (elementToRemove <= maxHeap.top()) {
                    maxHeap.remove(elementToRemove);
                }
                else {
                    minHeap.remove(elementToRemove);
                }
                rebalanceHeaps();
            }
        }
        return result;
    }
};

int main() {
    {
        Solution sln;
        int k = 3;
        vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
        vector<double> result = sln.medianSlidingWindow(nums, k);
        assert(1.00000 == result[0]);
        assert(-1.00000 == result[1]);
        assert(-1.00000 == result[2]);
        assert(3.00000 == result[3]);
        assert(5.00000 == result[4]);
        assert(6.00000 == result[5]);
    }
    {
        Solution sln;
        int k = 3;
        vector<int> nums{1, 2, 3, 4, 2, 3, 1, 4, 2};
        vector<double> result = sln.medianSlidingWindow(nums, k);
        assert(2.00000 == result[0]);
        assert(3.00000 == result[1]);
        assert(3.00000 == result[2]);
        assert(3.00000 == result[3]);
        assert(2.00000 == result[4]);
        assert(3.00000 == result[5]);
        assert(2.00000 == result[6]);
    }
    {
        Solution sln;
        int k = 2;
        vector<int> nums{2147483647, 1, 2, 3, 4, 5, 6, 7, 2147483647};
        vector<double> result = sln.medianSlidingWindow(nums, k);
        assert(1073741824.00000 == result[0]);
        assert(1.50000 == result[1]);
        assert(2.50000 == result[2]);
        assert(3.50000 == result[3]);
        assert(4.50000 == result[4]);
        assert(5.50000 == result[5]);
        assert(6.50000 == result[6]);
        assert(1073741827.00000 == result[7]);
    }
    {
        Solution sln;
        int k = 2;
        vector<int> nums{2147483647, 2147483647};
        vector<double> result = sln.medianSlidingWindow(nums, k);
        assert(2147483647.00000 == result[0]);
    }
    return 0;
}