#include "main.hpp"

class Solution {
public:
    // Sliding window approach.
    int totalFruit(vector<int>& fruits) {
        // Map to hold fruit frequency.
        unordered_map<int, int> m;

        int startWindow = 0;
        int totalCollection = 0;

        // Try extend the range from [windowStart, windowEnd].
        for (int endWindow = 0; endWindow < fruits.size(); ++endWindow) {
            ++m[fruits[endWindow]];

            // Shrink the window until we are left with 2 types of fruits in the map.
            if (m.size() > 2) {
                --m[fruits[startWindow]];

                if (m[fruits[startWindow]] == 0) {
                    m.erase(fruits[startWindow]);
                }

                // Shrink the window.
                ++startWindow;
            }
            totalCollection = std::max(totalCollection, endWindow - startWindow + 1);
        }
        return totalCollection;
    }
};

int main() {
    Solution sln;
    {
        vector<int> v{1, 2, 1};
        assert(3 == sln.totalFruit(v));
    }
    {
        vector<int> v{0, 1, 2, 2};
        assert(3 == sln.totalFruit(v));
    }
    {
        vector<int> v{1, 2, 3, 2, 2};
        assert(4 == sln.totalFruit(v));
    }
    return 0;
}