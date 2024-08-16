//
// Created by RobertRochlin on 8/16/2024.
//

#ifndef LEETCODE_78_SUBSETS_H
#define LEETCODE_78_SUBSETS_H
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result){
    result.push_back(curr);
    for (int i = start; i<nums.size(); i++){
        curr.push_back(nums[i]);
        dfs(nums, i+1, curr, result);
        curr.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        dfs(nums, 0, curr, res);
        return res;
    }
};
#endif //LEETCODE_78_SUBSETS_H
