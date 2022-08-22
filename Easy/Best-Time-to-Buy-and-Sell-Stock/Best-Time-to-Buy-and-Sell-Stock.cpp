#include "main.hpp"

class Solution {
public:
    /*int maxProfit(vector<int>& prices) {
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
    }*/
    int maxProfit(vector<int>& prices) {
        int l = 0; // Buying.
        int r = 1; // Selling.
        int maxProfit = 0;

        while (r < prices.size()) {
            // If buying price is less than selling price.
            if (prices[l] < prices[r]) {
                int currProfit = prices[r] - prices[l];
                maxProfit = std::max(maxProfit, currProfit);
            }
            // If selling price is less than previously bought price, then
            // update the buying price to current selling price because we
            // want to maximize our profit.
            else {
                l = r;
            }
            ++r;
        }
        return maxProfit;
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
