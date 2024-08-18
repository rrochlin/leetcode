//
// Created by Robert Rochlin on 8/17/24.
//

#ifndef LEETCODE_17_LETTERCOMBOPHONENUM_H
#define LEETCODE_17_LETTERCOMBOPHONENUM_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<char> get_letters(char num){
    int x = num-'0';
    int char_start = (x-2)*3 + 'a';
    if(x>7) char_start++;
    char start = (char)char_start;
    vector<char> res {start, char(start+1), char(start+2)};
    if (x==7 || x==9) res.push_back(char (start+3));
    return res;
}

void helper(vector<string>& res, string& curr, int idx, string& digits){
    if(idx==digits.size()) {
        res.push_back(curr);
        return;
    }
    auto letters = get_letters(digits[idx]);
    for(int i=0; i<letters.size(); i++){
        curr+=letters[i];
        helper(res, curr, idx+1, digits);
        curr.pop_back();
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string curr;
        helper(res, curr, 0, digits);
        return res;
    }
};


#endif //LEETCODE_17_LETTERCOMBOPHONENUM_H
