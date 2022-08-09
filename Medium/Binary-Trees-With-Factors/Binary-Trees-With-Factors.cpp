#include "main.hpp"

class Solution {
public:
    int mod = 1e9 + 7;
    using LL = long long;

    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        unordered_map<LL, LL> dp;
        
        for (LL i =0; i < arr.size(); ++i) {
            dp[arr[i]] = 1;
        }
        
        for (int i = 1; i < arr.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (arr[i] % arr[j] == 0) {
                    int right = arr[i]/arr[j];
                    
                    if (dp[right]) {
                        dp[arr[i]] = (dp[arr[i]] + (dp[arr[j]] * dp[right])) % mod;
                    }
                }
            }
        }
        
        int sum = 0;
        for (LL i = 0; i < arr.size(); ++i) {
            sum = (sum + dp[arr[i]]) % mod;
        }

        return sum;
    }
};

int main() {
    Solution sln;
    {
        vector<int> nums {2, 4};
        assert(3 == sln.numFactoredBinaryTrees(nums));
    }
    {
        vector<int> nums {2, 4, 5, 10};
        assert(7 == sln.numFactoredBinaryTrees(nums));
    }
    {
        vector<int> nums {3, 4};
        assert(2 == sln.numFactoredBinaryTrees(nums));
    }
    return 0;
}