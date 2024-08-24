//
// Created by Robert Rochlin on 8/20/24.
//

#ifndef LEETCODE_322_COINCHANGE_H
#define LEETCODE_322_COINCHANGE_H
#include <vector>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 1;
        vector<int> v(amount+1, amount+1);
        v[0] = 0;
        for (int i=0; i<amount+1; i++){
            for (int j=0; j<coins.size(); j++){
                if(coins[j]<=i) v[i] = min(v[i], 1+v[i-coins[j]]);
            }
        }
        return v[amount]<amount+1 ? v[amount] : -1;
    }
};

#endif //LEETCODE_322_COINCHANGE_H