//
// Created by Robert Rochlin on 8/25/24.
//

#ifndef LEETCODE_300_LONGESTINCREASINGSUBSEQUENCE_H
#define LEETCODE_300_LONGESTINCREASINGSUBSEQUENCE_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> dp(n,1);
        int res = 1;
        for (int i=n-2; i>=0; i--){
            for (int j=i+1; j<n; j++){
                if(nums[i]<nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
            }
            if(dp[i]>res) res=dp[i];
        }
        return res;
    }

    int lengthOfLISBetter(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }

        }
        return ans.size();

    }
};

#endif //LEETCODE_300_LONGESTINCREASINGSUBSEQUENCE_H
