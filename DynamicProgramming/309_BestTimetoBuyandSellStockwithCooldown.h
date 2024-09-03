//
// Created by Robert Rochlin on 8/30/24.
//

#ifndef LEETCODE_309_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H
#define LEETCODE_309_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H

#include <vector>
using namespace std;

// very slow solution

int helper(vector<int>& prices, int idx, bool can_buy, int stock, int n, vector<vector<int>>& dp){
    if(idx>=n) return 0;
    if(!can_buy && stock==1001) helper(prices, idx + 1, true, 1001, n, dp);
    if(dp[idx][stock]!=INT_MIN) return dp[idx][stock];
    if(stock==1001) {
        auto res = max(
                helper(prices, idx + 1, false, prices[idx], n, dp),
                helper(prices, idx + 1, true, 1001, n, dp)
        );
        dp[idx][stock] = res;
        return res;
    }
    auto res =  max(
            prices[idx]-stock + helper(prices, idx+1, false, 1001, n, dp),
            helper(prices, idx+1, false, stock, n, dp)
            );
    dp[idx][stock] = res;
    return res;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(1002, INT_MIN));
        return helper(prices, 0, true, 1001, n, dp);
    }

    int maxProfitFast(vector<int>& prices) {
        int sold = 0;
        int hold = INT_MIN;
        int rest = 0;

        for (int i = 0; i < prices.size(); i++) {
            int prevSold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prevSold);
        }

        return max(sold, rest);
    }

};

#endif //LEETCODE_309_BESTTIMETOBUYANDSELLSTOCKWITHCOOLDOWN_H
