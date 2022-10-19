#include "main.hpp"

// Min-heap approach.

class Solution {
    struct freqComp {
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
            // If frequency is same, then order lexicographically.
            if (p1.second == p2.second) {
                return p1.first < p2.first;
            }
            else {
                return p1.second > p2.second;
            }
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Store the frequency of each word.
        unordered_map<string, int> wordsFreq;
        
        for (auto word : words) {
            ++wordsFreq[word];
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, freqComp> minHeap;
        
        // Go through all the frequencies in the hash-table and push them in the minHeap, which will
        // have top K-frequent words. If the size of the minHeap is more than K, then remove the smallest (top) number.
        for (auto wordFreq : wordsFreq) {
            minHeap.push(wordFreq);
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // Store in set to store in sorted order.
        vector<string> result(k);
        int i = k - 1;
        
        while (!minHeap.empty()) {
            result[i--] = minHeap.top().first;
            minHeap.pop();
        }
        
        // Return as a vector.
        return result;
    }
};

int main() {
    Solution sln;
    {
        int k = 2;
        vector<string> words {"i","love","leetcode","i","love","coding"};
        vector<string> output {"i","love"};
        assert(output == sln.topKFrequent(words, k));
    }
    {
        int k = 4;
        vector<string> words {"the","day","is","sunny","the","the","the","sunny","is","is"};
        vector<string> output {"the","is","sunny","day"};
        assert(output == sln.topKFrequent(words, k));
    }
    return 0;
}