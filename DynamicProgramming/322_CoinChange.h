//
// Created by Robert Rochlin on 8/20/24.
//

#ifndef LEETCODE_322_COINCHANGE_H
#define LEETCODE_322_COINCHANGE_H
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<0) return INT_MAX;
        if(amount==0) return 1;
        int res = INT_MAX;
        for (int coin : coins){
            res = min(res, coinChange(coins, amount-coin));
        }
        return res;
    }
};

#endif //LEETCODE_322_COINCHANGE_H
