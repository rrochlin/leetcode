//
// Created by Robert Rochlin on 9/3/24.
//

#ifndef LEETCODE_494_TARGETSUM_H
#define LEETCODE_494_TARGETSUM_H

#include <vector>

using namespace std;


int helper(vector<int>& nums, int target, int n, int idx, vector<vector<int>>& dp){
    if(n==idx) return target==0;
    if(dp[idx][target+2000]!=-1) return dp[idx][target+2000];
    int res =
            helper(nums, target-nums[idx], n, idx+1, dp) +
            helper(nums, target+nums[idx], n, idx+1, dp);
    dp[idx][target+2000] = res;
    return res;
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4001,-1));
        return helper(nums, target, n, 0, dp);
    }
};

#endif //LEETCODE_494_TARGETSUM_H
