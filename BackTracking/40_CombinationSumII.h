//
// Created by Robert Rochlin on 8/16/24.
//

#ifndef LEETCODE_40_COMBINATIONSUMII_H
#define LEETCODE_40_COMBINATIONSUMII_H
#include <vector>
#include <set>
using namespace std;

void helper(vector<vector<int>>& res, int start, vector<int>& curr, vector<int>& nums, int target){
    if (target<0) return;
    if(target==0) {res.push_back(curr); return;}
    for (int i=start; i<nums.size(); i++){
        curr.push_back(nums[i]);
        helper(res, i+1, curr, nums, target-nums[i]);
        curr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1])i++;
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        helper(res, 0, curr, candidates, target);
        return res;
    }
};
#endif //LEETCODE_40_COMBINATIONSUMII_H
