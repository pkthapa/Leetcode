#include "main.hpp"

class Solution {
public:
    // Approach 1: Boyer–Moore majority vote algorithm.
    //
    // Intuition Behind Working:
    // When the elements are the same as the candidate element, votes are incremented.
    // When some other element is found not equal to the candidate element, we decrease the count.
    // This actually means that we are decreasing the priority of winning ability of the selected candidate, since we know that
    // if the candidate is a majority it occurs more than N/2 times and the remaining elements are less than N/2.
    // We keep decreasing the votes since we found some different element than the candidate element.
    // When votes become 0, this actually means that there are the same number of different elements, which should not be the case for the element
    // to be the majority element. So the candidate element cannot be the majority, so we choose the present element as the candidate
    // and continue the same till all the elements get finished. The final candidate would be our majority element.
    // We check using the 2nd traversal to see whether its count is greater than N/2.
    // If it is true, we consider it as the majority element.
    int majorityElement(vector<int>& nums) {
        int me = nums[0];
        int votes = 1; // Starting with '1' because 'me' is initialized with nums[0].

        for (int i = 1; i < nums.size(); ++i) { // Start from next
            if (nums[i] == me) {
                ++votes;
            }
            else if (0 == votes) {
                me = nums[i];
            }
            else {
                --votes;
            }
        }
        return me;
    }

    // Approach 2: Using hash table.
    int majorityElementUsingHashTable(vector<int>& nums) {
        unordered_map<int, int> m;
        
        int majEle = 0;
        int maxCount = 0;
        for (auto i : nums) {
            ++m[i];
            if (m[i] > maxCount) {
                maxCount = m[i];
                majEle = i;
            }
        }
        return majEle;
    }
};

int main() {
    Solution sln;
    {
        vector<int> v{3, 2, 3};
        assert(3 == sln.majorityElement(v));
        assert(3 == sln.majorityElementUsingHashTable(v));
    }
    {
        vector<int> v{2, 2, 1, 1, 1, 2, 2};
        assert(2 == sln.majorityElement(v));
        assert(2 == sln.majorityElementUsingHashTable(v));
    }
    return 0;
}
