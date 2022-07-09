#include "main.hpp"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;

        for (auto i : nums1) {
            ++m[i];
        }

        vector<int> res;
        for (auto i : nums2) {
            if (m[i] > 0) {
                res.push_back(i);
                m.erase(i);
            }
        }
        return res;
    }
};

int main() {
    Solution sln;
    {
        vector<int> v1 {1, 2, 2, 1};
        vector<int> v2 {2, 2};
        vector<int> res {2};
        assert(res == sln.intersection(v1, v2));
    }
    {
        vector<int> v1 {4, 9, 5};
        vector<int> v2 {9, 4, 9, 8, 4};
        vector<int> res {9, 4};
        assert(res == sln.intersection(v1, v2));
    }
    {
        vector<int> v1 {1, 2, 2, 1, 9, 3};
        vector<int> v2 {1, 3, 9};
        vector<int> res {1, 3, 9};
        assert(res == sln.intersection(v1, v2));
    }
    return 0;
}