//
// Created by Robert Rochlin on 8/27/24.
//

#ifndef LEETCODE_1143_LONGESTCOMMONSUBSEQUENCE_H
#define LEETCODE_1143_LONGESTCOMMONSUBSEQUENCE_H
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
#endif //LEETCODE_1143_LONGESTCOMMONSUBSEQUENCE_H
