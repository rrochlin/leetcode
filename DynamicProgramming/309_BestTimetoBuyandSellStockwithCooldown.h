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
    if(dp[idx][can_buy]!=INT_MIN) return dp[idx][can_buy];
    if(can_buy) {
        auto res = max(
                helper(prices, idx + 1, false, prices[idx], n, dp) - prices[idx], // buy
                helper(prices, idx + 1, true, INT_MIN, n, dp) // hold
        );
        dp[idx][can_buy] = res;
        return res;
    }
    auto res =  max(
            prices[idx] + helper(prices, idx+2, true, INT_MIN, n, dp), // sell -> cd
            helper(prices, idx+1, false, stock, n, dp) // hold
            );
    dp[idx][can_buy] = res;
    return res;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        return helper(prices, 0, true, INT_MIN, n, dp);
    }

    int maxProfitMinSpace(vector<int>& prices) {
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
