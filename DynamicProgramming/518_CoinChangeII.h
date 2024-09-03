//
// Created by RobertRochlin on 9/2/2024.
//

#ifndef LEETCODE_518_COINCHANGEII_H
#define LEETCODE_518_COINCHANGEII_H
#include <vector>

using namespace std;

int helper(int amount, vector<int>& coins, vector<int>& dp){
    if(amount<=0) return amount!=0;
    int ways = 0;
    for (int i : coins){
        ways += helper(amount-i, coins, dp);
    }
    return ways;
}
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, INT_MAX);
        return helper(amount, coins, dp);
    }
};
#endif //LEETCODE_518_COINCHANGEII_H
