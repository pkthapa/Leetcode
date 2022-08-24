#include "main.hpp"

class Solution {
public:
    // Keeps inserting smaller elements in the deck.
    // If bigger element is found, then remove all smaller element from the deck.
    // The idea is to keep the deck filled with elements in decreasing order.
    // If window is shifted, then extract the first element from the deck, because the deque[0]
    // will contain the maximum element in the deck.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<int> dq; // Holds the indices of 'nums'.

        int windowStart = 0;
        int windowEnd = 0;

        while (windowEnd < nums.size()) {
            while (!dq.empty() &&
                   // If current element of 'nums' is greater than every element in deck comparing from the back, then remove
                   // all smaller elements from the deck.
                   nums[dq.back()] < nums[windowEnd]) {
                dq.pop_back();
            }

            dq.push_back(windowEnd); // Store the index in deque.

            // Remove the first inserted index from the deck (deque), if the
            // 'windowStart' goes out of scope.
            if (windowStart > dq[0]) {
                dq.pop_front();
            }

            if (windowEnd + 1 >= k) {
                // Insert the first inserted element in the output.
                // Remember, dq stores the indices of 'nums'.
                output.emplace_back(nums[dq[0]]);
                ++windowStart;
            }
            ++windowEnd;
        }
        return output;
    }
};

int main() {
    Solution sln;
    {
        int k = 3;
        vector<int> nums {1, 3, -1, -3, 5, 3, 6, 7};
        vector<int> output {3, 3, 5, 5, 6, 7};
        assert(output == sln.maxSlidingWindow(nums, k));
    }
    {
        int k = 1;
        vector<int> nums {1};
        vector<int> output {1};
        assert(output == sln.maxSlidingWindow(nums, k));
    }
    return 0;
}