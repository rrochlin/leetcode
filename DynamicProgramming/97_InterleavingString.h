//
// Created by Robert Rochlin on 9/4/24.
//

#ifndef LEETCODE_97_INTERLEAVINGSTRING_H
#define LEETCODE_97_INTERLEAVINGSTRING_H

#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int ns1 = s1.size(), ns2 = s2.size(), ns3 = s3.size();
        if (ns1 + ns2 != ns3) return false;
        vector<vector<bool>> dp(ns1 + 1, vector<bool>(ns2 + 1));
        for (int i = ns1; i >= 0; i--) {
            for (int j = ns2; j >= 0; j--) {
                if ((i + j == ns3) ||
                    (i < ns1 && s1[i] == s3[i + j] && dp[i + 1][j]) ||
                    (j < ns2 && s2[j] == s3[i + j] && dp[i][j + 1])) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
};

#endif //LEETCODE_97_INTERLEAVINGSTRING_H
