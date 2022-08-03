#include "main.hpp"

class Solution {
public:
    // TC: O (m + n)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // To store the element against the index.
        unordered_map<int, int> m;

        for (int i = 0; i < nums1.size(); ++i) {
            m[nums1[i]] = i;
        }
        
        vector<int> result(nums1.size(), -1);
        stack<int> stk; // Monotonic stack.

        for (int i = 0; i < nums2.size(); ++i) {
            int curr = nums2[i];

            // If 'curr' is greater then keep removing the top elements
            // from the stack. And get the index of the removed elements from the map 'm'.
            // Update the 'result' on that index with the element responsible for deleting from stack.
            while (!stk.empty() && curr > stk.top()) {
                int idx = m[stk.top()];
                stk.pop();
                result[idx] = curr;
            }

            if (m.count(curr) > 0) {
                stk.push(curr);
            }
        }
        return result;
    }

    /*
    // TC: O (n * m)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // To store the element against the index.
        unordered_map<int, int> m;
        vector<int> result(nums1.size(), -1);
        
        for (int i = 0; i < nums2.size(); ++i) {
            m[nums2[i]] = i;
        }
        
        for (int i = 0; i < nums1.size(); ++i) {
            int num1 = nums1[i];

            if (m.count(num1) > 0) {
                auto offset = m[num1]; // Get the offset of 'num1' in 'nums2' from the hash-map.
                
                for (int j = offset + 1; j < nums2.size(); ++j) {
                    if (num1 < nums2[j]) {
                        result[i] = nums2[j];
                        break;
                    }
                }
            }
        }
        return result;
    }
    */
};

int main() {
    Solution sln;
    {
        vector<int> nums1 {4, 1, 2};
        vector<int> nums2 {1, 3, 4, 2};
        vector<int> result {-1, 3, -1};
        assert(result == sln.nextGreaterElement(nums1, nums2));
    }
    {
        vector<int> nums1 {2, 4};
        vector<int> nums2 {1, 2, 3, 4};
        vector<int> result {3, -1};
        assert(result == sln.nextGreaterElement(nums1, nums2));
    }
    {
        vector<int> nums1 {4, 2, 8, 5};
        vector<int> nums2 {1, 3, 4, 2, 6, 8, 5};
        vector<int> result {6, 6, -1, -1};
        assert(result == sln.nextGreaterElement(nums1, nums2));
    }
    return 0;
}