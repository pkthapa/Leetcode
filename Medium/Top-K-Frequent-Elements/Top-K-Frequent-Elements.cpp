#include "main.hpp"

// Min-heap based approach.

class Solution {
    struct myComparator {
        // pair<number, frequency>
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>&& nums, int k) {
        // Store the frequencies of each number.
        unordered_map<int, int> freq;
        
        for (auto num : nums) {
            ++freq[num];
        }
        
        // Intuition: Since we need highest number of frequently occurring numbers,
        // so keeping only k {number, frequency} pair in the min-heap based on the
        // frequency count.
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparator> minHeap;
        
        for (auto f : freq) {
            minHeap.push(f);
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        int i = 0;
        vector<int> result(k);
        while (!minHeap.empty()) {
            result[i++] = minHeap.top().first;
            minHeap.pop();
        }
        return result;
    }
};

#if 0
// Credits: https://www.youtube.com/watch?v=YPTqKIgVk-k&ab_channel=NeetCode
class Solution {
public:
    vector<int> topKFrequent(vector<int>&& nums, int k) {
        unordered_map<int, int> m;
        
        for (auto num : nums) {
            ++m[num];
        }
        
        // Maps the occurence count from map 'm' to the indices of the 'arr'.
        // Store the vector of numbers in corresponding indices (considered as occurence count).
        vector<vector<int>> arr(nums.size() + 1, vector<int>());
        
        for (auto i : m) {
            arr[i.second].emplace_back(i.first);
        }

        /*
        E.g. nums = [1, 1, 1, 2, 2, 3], k = 2

        Indices: 0 | 1 | 2 | 3 | 4 | 5 | 6
                ---------------------------
        Numbers: x | 3 | 2 | 1 | x | x | x
        
        Here, 1 is repeated thrice, hence it sits on 3rd offset.
        2 is repeated twice, hence it sits on 2nd offset.
        3 is single, hence it sits on 1st offset.
        */
        vector<int> result;
        for (int i = arr.size() - 1; i >= 0; --i) {
            vector<int> innerVect (arr[i]);

            if (innerVect.size() > 0) {
                for (auto n : innerVect) {
                    result.emplace_back(n);
                    --k;
                }

                if (k == 0) { break; }
            }
        }
        return result;
    }
};
#endif

int main() {
    Solution sln;
    {
        vector<int> result {2, 1};
        assert(result == sln.topKFrequent({1, 1, 1, 2, 2, 3}, 2));
    }
    {
        vector<int> result {1};
        assert(result == sln.topKFrequent({1}, 1));
    }
    return 0;
}