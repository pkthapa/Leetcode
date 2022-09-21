#include "main.hpp"

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // Calculate the total even sum before starting with modification.
        int evenSum = 0;
        int qSize = queries.size();
        vector<int> output(qSize);
        
        // Get the sum of all even numbers from 'nums'.
        for (auto num : nums) {
            if (num % 2 == 0) {
                evenSum += num;
            }
        }
        
        for (int i = 0; i < qSize; ++i) {
            int index = queries[i][1];
            int val = queries[i][0];
            
            // Subtract the value from 'nums' if it is even because we have added total even sum before reaching here.
            if (nums[index] % 2 == 0) {
                evenSum -= nums[index];
            }
            
            nums[index] += val;
            
            // Check if it is still even after adding 'val', then add the modified 'nums[index]'
            // to total even sum because we had subtracted above.
            if (nums[index] % 2 == 0) {
                evenSum += nums[index];
            }
            
            output[i] = evenSum;
        }
        return output;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {1, 2, 3, 4};
        vector<vector<int>> queries {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
        vector<int> output {8, 6, 2, 4};
        assert(output == sln.sumEvenAfterQueries(nums, queries));
    }
    {
        vector<int> nums {1};
        vector<vector<int>> queries {{4, 0}};
        vector<int> output {0};
        assert(output == sln.sumEvenAfterQueries(nums, queries));
    }
    return 0;
}