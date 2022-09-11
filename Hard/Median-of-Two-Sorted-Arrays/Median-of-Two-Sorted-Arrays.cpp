#include "main.hpp"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> mergedArr(m + n);
        
        int l = 0;
        int r = 0;
        int i = 0;
        while (l < m && r < n) {
            if (nums1[l] < nums2[r]) {
                mergedArr[i++] = nums1[l++];
            }
            else {
                mergedArr[i++] = nums2[r++];
            }
        }
        
        while (l < m) {
            mergedArr[i++] = nums1[l++];
        }
        
        while (r < n) {
            mergedArr[i++] = nums2[r++];
        }
        
        int sz = mergedArr.size();
        double median = 0.0F;
        if (sz % 2 == 0) {
            median = (double)(mergedArr[sz / 2] + mergedArr[(sz / 2) - 1]) / 2;
        }
        else {
            median = mergedArr[sz / 2];
        }
        return median;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums1{1, 3};
        vector<int> nums2{2};
        assert(2.00000 == sln.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1{1, 2};
        vector<int> nums2{3, 4};
        assert(2.50000 == sln.findMedianSortedArrays(nums1, nums2));
    }
    {
        vector<int> nums1{-100, -30, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 100, 122};
        vector<int> nums2{-2, -2, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 99, 100};
        assert(4.00000 == sln.findMedianSortedArrays(nums1, nums2));
    }
    return 0;
}