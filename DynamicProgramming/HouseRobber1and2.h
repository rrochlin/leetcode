//
// Created by Robert Rochlin on 8/19/24.
//

#ifndef LEETCODE_198_HOUSEROBBER_H
#define LEETCODE_198_HOUSEROBBER_H
#include <vector>
using namespace std;

class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> tab(n);
        tab[0]=nums[0];
        tab[1]=nums[1];
        tab[3]=max(nums[1], nums[2]+nums[0]);
        for (int i=3; i<n; i++) tab[i] = max(max(tab[i-1], tab[i-2]+nums[i]), tab[i-3]+nums[i]);
        return max(tab[n-1], tab[n-2]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = nums[0];
        for(int i=2;i<n-1;i++) {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }
        int first=dp[n-2];
        dp.clear();
        dp[0]=0;
        dp[1]=nums[1];
        for(int i=2;i<n;i++) {
            dp[i]=max(dp[i-1], dp[i-2]+nums[i]);
        }
        return max(dp[n-1], first);

    }
};

#endif //LEETCODE_198_HOUSEROBBER_H
