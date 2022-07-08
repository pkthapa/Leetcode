#include "main.hpp"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        // Lets sort the input vector.
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i){
            if (i > 0 and nums[i - 1] == nums[i]){
                // If nums are same, then move start index to another index.
                continue;
            }

            auto l = i + 1;
            auto r = nums.size() - 1;
            
            // Lets do 2-sum for sorted array.
            while (l < r){
                auto threeSum = nums[i] + nums[l] + nums[r];
                
                if (threeSum < 0){
                    // Move left pointer to right.
                    ++l;
                }
                else if (threeSum > 0){
                    // Move right pointer to left.
                    --r;
                }
                else {
                    // If threeSum is equal to 0, then store the triplets.
                    vector<int> v {nums[i], nums[l], nums[r]};
                    result.push_back(v);
                    ++l; // Increment to next offset and do below check.
                    
                    // Check if nums of new left index is same as previous left index.
                    // If same, then move left index towards right.
                    while (nums[l - 1] == nums[l] and l < r){
                        ++l;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sln;
    {
        vector<int> v{-1, 0, 1, 2, -1, -4};
        vector<vector<int>> output {{-1, -1, 2}, {-1, 0, 1}};
        assert(output == sln.threeSum(v));
    }
    {
        vector<int> v{};
        vector<vector<int>> output {};
        assert(output == sln.threeSum(v));
    }
    {
        vector<int> v{0};
        vector<vector<int>> output {};
        assert(output == sln.threeSum(v));
    }
    return 0;
}