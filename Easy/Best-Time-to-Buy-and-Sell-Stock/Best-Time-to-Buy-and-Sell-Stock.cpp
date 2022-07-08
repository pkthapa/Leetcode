#include "main.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT32_MAX;
        
        for (int i = 0; i < prices.size(); ++i){
            if (prices[i] < minPrice){
                minPrice = prices[i];
            }
            else if (prices[i] - minPrice > profit){
                profit = prices[i] - minPrice;
            }
        }

        return profit;
    }
};

int main() {
    Solution sln;

    vector<int> prices {7, 1, 5, 3, 6, 4};
    assert(5 == sln.maxProfit(prices));

    vector<int> prices1 {7, 6, 4, 3, 1};
    assert(0 == sln.maxProfit(prices1));

    return 0;
}