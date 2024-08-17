//
// Created by RobertRochlin on 8/16/2024.
//

#ifndef LEETCODE_90_SUBSETSII_H
#define LEETCODE_90_SUBSETSII_H
#include <vector>
#include <set>
using namespace std;

class SolutionFaster {
public:

    void Util(vector<int>& nums, int ind, int n, vector<vector<int>> &ans, vector<int>&temp) {
        if(ind==n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        Util(nums, ind+1, n, ans, temp);
        temp.pop_back();
        Util(nums, ind+1, n, ans, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        Util(nums, 0, nums.size(), ans, temp);
        set<vector<int>> s(ans.begin(), ans.end());
        ans.resize(s.size());
        copy(s.begin(), s.end(), ans.begin());
        return ans;
    }
};

void helper(vector<vector<int>>& res, int start, vector<int>& curr, vector<int>& nums ) {
    res.push_back(curr);
    for (int i=start; i<nums.size(); i++){
        curr.push_back(nums[i]);
        helper(res, i+1, curr, nums);
        curr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
    }
}

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        helper(res, 0, curr, nums);
        return res;
    }
};
#endif //LEETCODE_90_SUBSETSII_H
