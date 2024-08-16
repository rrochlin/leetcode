//
// Created by RobertRochlin on 8/16/2024.
//

#ifndef LEETCODE_90_SUBSETSII_H
#define LEETCODE_90_SUBSETSII_H
#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& res, int start, vector<int>& curr, vector<int>& nums ) {
    res.push_back(curr);
    for (int i=start; i<nums.size(); i++){
        curr.push_back(nums[i]);
        helper(res, i+1, curr, nums);
        curr.pop_back();
        while()
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
