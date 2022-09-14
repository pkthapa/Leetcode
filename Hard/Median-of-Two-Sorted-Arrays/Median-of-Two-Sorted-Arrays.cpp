#include "main.hpp"

class Solution {
public:
    // https://www.youtube.com/watch?v=yD7wV8SyPrc&ab_channel=KeertiPurswani
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Let's do the binary search on the smaller array to get the best time complexity.
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0;
        int high = n1;
        
        while (low <= high) {
            int cut1 = (low + high) >> 1; //(low + (high - low)) / 2;
            int cut2 = ((n1 + n2) >> 1) - cut1; // 'n >> 1' means  'n / 2'.
            
            int l1 = (cut1 == 0) ? INT32_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT32_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT32_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT32_MAX : nums2[cut2];
            
            /*
            Condition to satisfy:
            l1 < r2
            l2 < r1
            */
            if (l1 > r2) {
                high = cut1 - 1;
            }
            else if (l2 > r1) {
                low = cut1 + 1;
            }
            else {
                return ((n1 + n2) % 2 == 0) ?
                    static_cast<double>(max(l1, l2) + min(r1, r2)) / 2 :
                    static_cast<double>(min(r1, r2));
            }
        }
        return 0.0F;
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
