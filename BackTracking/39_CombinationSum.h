//
// Created by RobertRochlin on 8/16/2024.
//

#ifndef LEETCODE_39_COMBINATIONSUM_H
#define LEETCODE_39_COMBINATIONSUM_H
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& res, int start, vector<int>& curr, vector<int>& nums, int& target, int sum){
    if(sum==target) res.push_back(curr);
    else if(sum>target) return;
    for (int i=start; i<nums.size(); i++){
        curr.push_back(nums[i]);
        sum+=nums[i];
        dfs(res, i+1, curr, nums, target, sum);
        int newsum=nums[i];
        auto temp = curr;
        while(sum+newsum<=target){
           temp.push_back(nums[i]);
           dfs(res, i+1, temp, nums, target, sum+newsum);
           newsum+=nums[i];
        }
        sum-=nums[i];
        curr.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        res.reserve(150);
        vector<int> curr;
        dfs(res, 0, curr, candidates, target, 0);
        return res;
    }
};
#endif //LEETCODE_39_COMBINATIONSUM_H
