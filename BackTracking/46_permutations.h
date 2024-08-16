//
// Created by RobertRochlin on 8/16/2024.
//

#ifndef LEETCODE_46_PERMUTATIONS_H
#define LEETCODE_46_PERMUTATIONS_H
#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, deque<int>& indices){
    if(indices.empty()) res.push_back(curr);
    else {
        int k = indices.size();
        for(int i=0; i<k; i++){
            auto next = indices.front();
            indices.pop_front();
            curr.push_back(next);
            helper(res, curr, nums, indices);
            indices.push_back(next);
            curr.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        deque<int> indices;
        for(int i=0; i<nums.size(); i++) indices.push_back(nums[i]);
        helper(res, curr, nums, indices);
        return res;
    }
};

#endif //LEETCODE_46_PERMUTATIONS_H
