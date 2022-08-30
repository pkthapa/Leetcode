#include "main.hpp"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary search technique.
        int n = piles.size();
        int l = 1;
        int r = 0;

        // Get the highest pile from 'piles'.
        for (int i = 0; i < n; ++i) {
            r = std::max(r, piles[i]);
        }
        
        // Init the result with the highest pile banana count.
        int result = r;

        while (l <= r) {
            int k = (l + r) / 2;
            long int hours = 0;
            
            for (int i = 0; i < n; ++i) {
                hours += ceil(((double)piles[i] / k));
            }

            if (hours <= h) {
                result = std::min(result, k);
                r = k - 1;
            }
            else {
                l = k + 1;
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        int h = 8;
        vector<int> piles {3, 6, 7, 11};
        assert(4 == sln.minEatingSpeed(piles, h));
    }
    {
        int h = 5;
        vector<int> piles {30, 11, 23, 4, 20};
        assert(30 == sln.minEatingSpeed(piles, h));
    }
    {
        int h = 6;
        vector<int> piles {30, 11, 23, 4, 20};
        assert(23 == sln.minEatingSpeed(piles, h));
    }
    return 0;
}