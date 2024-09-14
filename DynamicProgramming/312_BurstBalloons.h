//
// Created by Robert Rochlin on 9/9/24.
//

#ifndef LEETCODE_312_BURSTBALLOONS_H
#define LEETCODE_312_BURSTBALLOONS_H

#include <vector>
#include <unordered_map>

using namespace std;

int helper(vector<int>& nums, int sum, int n, vector<unordered_map<int, int>>& dp){
    if (n==2) return sum + nums[0] * nums[1] + max(nums[0], nums[1]);
    if (dp[n].find(sum)!=dp[n].end()) return dp[n][sum];
    int res = 0;
    for (int i=0; i<n; i++){
        int num = nums[i];
        int val = num;
        if (i>0) val*=nums[i-1];
        if (i<n-1) val*=nums[i+1];
        nums.erase(nums.begin()+i);
        res = max(helper(nums, sum+val, n-1, dp), res);
        nums.insert(nums.begin()+i, num);
    }
    dp[n][sum] = res;
    return res;
}
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector<unordered_map<int, int>> dp(n+1, unordered_map<int, int>());
        return helper(nums, 0, n, dp);
    }
};


#endif //LEETCODE_312_BURSTBALLOONS_H
