//
// Created by RobertRochlin on 9/2/2024.
//

#ifndef LEETCODE_518_COINCHANGEII_H
#define LEETCODE_518_COINCHANGEII_H
#include <vector>

using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, 0));
        for (int i=0; i<coins.size(); i++){
            dp[i][0] = 1;
            for (int j=1;j<amount+1; j++){
                if(j-coins[i]>=0) dp[i][j] += dp[i][j-coins[i]];
                if(i>0) dp[i][j] += dp[i-1][j];
            }
        }
        return dp[coins.size()-1][amount];
    }
};
#endif //LEETCODE_518_COINCHANGEII_H
