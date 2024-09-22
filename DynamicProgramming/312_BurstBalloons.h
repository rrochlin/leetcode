//
// Created by Robert Rochlin on 9/9/24.
//

#ifndef LEETCODE_312_BURSTBALLOONS_H
#define LEETCODE_312_BURSTBALLOONS_H

#include <vector>

using namespace std;

int helper(vector<int>& nums, int L, int R, vector<vector<int>>& dp){
    if (L>R) return 0;
    int res = 0;
    for (int i=L; i<=R; i++){
        if(dp[i+1][R] == -1) dp[i+1][R] = helper(nums, i+1, R, dp);
        if(dp[L][i-1] == -1) dp[L][i-1] = helper(nums, L, i-1, dp);
        res = max(res, dp[L][i-1] + dp[i+1][R] + nums[i]*nums[L-1]*nums[R+1]);
    }
    return res;
}
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return helper(nums, 1, n, dp);
    }
};


#endif //LEETCODE_312_BURSTBALLOONS_H
