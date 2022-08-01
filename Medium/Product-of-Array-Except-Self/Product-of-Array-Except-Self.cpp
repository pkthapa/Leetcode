#include "main.hpp"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> output (n);
  
        // Calculate the product of all left-hand side elements.
        int product = 1;
        for (int i = 0; i < n; ++i) {
            product *= nums[i];
            output[i] = product;
        }
        
        // Calculate the product of all righ-hand side elements.
        product = 1;
        for (int i = n - 1; i > 0; --i) {
            output[i] = output[i - 1] * product;
            product *= nums[i];
        }
        output[0] = product;

        return output;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {1, 2, 3, 4};
        vector<int> output {24, 12, 8, 6};
        assert(output == sln.productExceptSelf(nums));
    }
    {
        vector<int> nums {-1, 1, 0, -3, 3};
        vector<int> output {0, 0, 9, 0, 0};
        assert(output == sln.productExceptSelf(nums));
    }
    return 0;
}