//
// Created by Robert Rochlin on 8/16/24.
//

#ifndef LEETCODE_131_PALINDROMEPARTITIONING_H
#define LEETCODE_131_PALINDROMEPARTITIONING_H
#include <string>
#include <vector>
using namespace std;

void helper(vector<vector<string>> &res, vector<string> &curr, int wordIdx, string &word){
    if(wordIdx>=word.length()) {
        for (int i=0; i<curr.size(); i++) {
            // this is complicated just do while left<right could be better
            auto c_f = curr[i].begin();
            auto c_b = curr[i].rbegin();
            for (int j = 0; j <= (curr[i].size() >> 1); j++) if (*c_f++ != *c_b++) return;
        }
        res.push_back(curr);
        return;
    }
    for (int i=wordIdx; i<word.size(); i++){
        curr.emplace_back(1,word[i]);
        helper(res, curr, i+1, word);
        curr.pop_back();
        curr.back()+=word[i];
    }
}

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr{string(1,s[0])};
        helper(res, curr, 1, s);
        return res;
    }
};

#endif //LEETCODE_131_PALINDROMEPARTITIONING_H
