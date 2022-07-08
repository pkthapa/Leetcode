#include "main.hpp"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int i{0}, j{1}; // Two pointers approach.
        
        for (; j < nums.size(); ++j){
            
            if (nums[i] != nums[j]){ // Both are same?
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N{0};
    cin >> N;

    vector<int> nums;
    Solution sln;

    int t{0};
    while (N-- > 0){
        cin >> t;
        nums.push_back(t);
    }

    auto cnt = sln.removeDuplicates(nums);

    for (int i = 0; i < cnt; ++i){
        cout << nums[i] << " ";
    }

    return 0;
}