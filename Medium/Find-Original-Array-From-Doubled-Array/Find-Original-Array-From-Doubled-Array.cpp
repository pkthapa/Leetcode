#include "main.hpp"

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) {
            return {};
        }

        unordered_map<int, int> c;
        for (int a : changed) {
            c[a]++;
        }
        
        vector<int> keys;
        for (auto it : c) {
            keys.push_back(it.first);
        }

        // Sorting is required inorder to make sure we start from the smallest number.
        // There will be no number to the left of the smallest number, so we will be sure that
        // our start point is that number and we may or may not have '2 * smallest number'.
        // Moving forward, our task is to find out whether we have atleast '2 * smallest number' count
        // equal to smallest number count.
        //sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        sort(keys.begin(), keys.end());

        vector<int> res;
        for (int x : keys) {
            if (c[x] > c[2 * x]) {
                return {};
            }

            for (int i = 0; i < c[x]; ++i, c[2 * x]--) {
                res.push_back(x);
            }
        }
        return res;
    }
};

int main() {
    Solution sln;
    {
        vector<int> original{1, 3, 4};
        vector<int> changed{1, 3, 4, 2, 6, 8};
        assert(original == sln.findOriginalArray(changed));
    }
    {
        vector<int> original{0, 0};
        vector<int> changed{0, 0, 0, 0};
        assert(original == sln.findOriginalArray(changed));
    }
    {
        vector<int> original{};
        vector<int> changed{1, 3, 4};
        assert(original == sln.findOriginalArray(changed));
    }
    return 0;
}