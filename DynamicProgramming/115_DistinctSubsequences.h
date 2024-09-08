//
// Created by Robert Rochlin on 9/7/24.
//

#ifndef LEETCODE_115_DISTINCTSUBSEQUENCES_H
#define LEETCODE_115_DISTINCTSUBSEQUENCES_H
#include <string>
#include <vector>
using namespace std;

int helper(string& s, string& t, int sz, int tz, int i, int c, vector<vector<int>>& dp){
    if(c==tz) return 1;
    if(sz-i+c < tz) return 0; //also will check the end
    if(dp[i][c]!=-1) return dp[i][c];
    int res = 0;
    if(s[i]==t[c]) res += helper(s, t, sz, tz, i+1, c+1, dp);
    res += helper(s, t, sz, tz, i+1, c, dp);
    dp[i][c]=res;
    return res;
}

class Solution {
public:
    int numDistinct(string s, string t) {
        int sz=s.size(), tz=t.size();
        if(sz==tz) return s==t;
        vector<vector<int>> dp(sz, vector<int>(tz, -1));
        return helper(s, t, sz, tz, 0, 0, dp);
    }
};

#endif //LEETCODE_115_DISTINCTSUBSEQUENCES_H
