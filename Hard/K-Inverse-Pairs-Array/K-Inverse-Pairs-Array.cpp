#include "main.hpp"

class Solution {
public:
    // Solution: https://www.youtube.com/watch?v=o7SxHFq6SPE
    int kInversePairs(int n, int k) {
        int MOD = 1e9 + 7;
        vector<vector<int>> dp (n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int N = 1; N <= n; ++N) {
            for (int K = 1; K <= k; ++K) {
                dp[N][K] = (dp[N - 1][K] + dp[N][K - 1]) % MOD;

                if (K - N >= 0) {
                    dp[N][K] = (dp[N][K] - dp[N - 1][K - N] + MOD) % MOD;
                }
            }
        }
        return dp[n][k];
    }
};

int main() {
    Solution sln;
    {
        constexpr int n = 3;
        constexpr int k = 0;
        assert(1 == sln.kInversePairs(n, k));
    }
    {
        constexpr int n = 3;
        constexpr int k = 1;
        assert(2 == sln.kInversePairs(n, k));
    }
    {
        constexpr int n = 1000;
        constexpr int k = 1000;
        assert(663677020 == sln.kInversePairs(n, k));
    }
    {
        constexpr int n = 1;
        constexpr int k = 1;
        assert(0 == sln.kInversePairs(n, k));
    }
    return 0;
}