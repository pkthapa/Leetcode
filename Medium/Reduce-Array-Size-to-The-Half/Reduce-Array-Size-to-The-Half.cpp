#include "main.hpp"

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int idx = 0;
        int n = arr.size();
        unordered_map<int, int> countFreq;

        // Store the frequency count.
        for (auto i : arr) {
            ++countFreq[i];
        }

        // Copy all map's value from key-value pair.
        vector<int> freqs(n);
        for (auto i : countFreq) {
            freqs[idx++] = i.second;
        }

        // Sort in decending order.
        sort(freqs.begin(), freqs.end(), std::greater<int>());

        idx = 0;
        int count = 0;
        int totalElements = n;

        // Start subtracting higher frequencies and check
        // if the result is lesser than n/2.
        // Keep on updating 'count'.
        while (totalElements > n/2) {
            totalElements -= freqs[idx++];
            ++count;
        }
        return count;
    }
};

int main() {
    Solution sln;
    {
        vector<int> arr {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
        assert(2 == sln.minSetSize(arr));
    }
    {
        vector<int> arr {7, 7, 7, 7, 7, 7};
        assert(1 == sln.minSetSize(arr));
    }
    return 0;
}