#include "main.hpp"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int l1 = 0, l2 = 0;
        int r1 = nums1.size(), r2 = nums2.size();

        vector<int> out;
        while (l1 < r1 and l2 < r2) {
            if (nums1[l1] == nums2[l2]) {
                out.push_back(nums1[l1]);
                ++l1;
                ++l2;
            }
            else if (nums1[l1] < nums2[l2]) {
                ++l1;
            }
            else {
                ++l2;
            }
        }
        return out;
    }
};

int main() {
    Solution sln;
    {
        vector<int> v1 {1, 2, 2, 1};
        vector<int> v2 {2, 2};
        vector<int> res {2, 2};
        assert(res == sln.intersect(v1, v2));
    }
    {
        vector<int> v1 {4, 9, 5};
        vector<int> v2 {9, 4, 9, 8, 4};
        vector<int> res {4, 9};
        assert(res == sln.intersect(v1, v2));
    }
    {
        vector<int> v1 {1, 2, 2, 1, 9, 3};
        vector<int> v2 {1, 3, 9};
        vector<int> res {1, 3, 9};
        assert(res == sln.intersect(v1, v2));
    }
    return 0;
}