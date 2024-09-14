//
// Created by Robert Rochlin on 9/8/24.
//

#ifndef LEETCODE_72_EDITDISTANCE_H
#define LEETCODE_72_EDITDISTANCE_H
#include <vector>

using namespace std;

int dfs(string word1, string word2, int i, int n, int m, vector<vector<int>>& dp){
    if(i==m) return word1.size()-i;
    if(i==n) return m-i;
    if(dp[i][n-i]!=-1) return dp[i][n-i];
    //it is known to be less than m & n
    if(word1[i]==word2[i]) return dfs(word1, word2, i+1, n, m, dp);
    //insert
    word1.insert(i, word2, i, 1);
    int res = 1 + dfs(word1, word2, i+1, n+1, m, dp);
    word1.erase(i, 1);
    //replace
    word1[i] = word2[i];
    res = min(res, 1 + dfs(word1, word2, i+1, n, m, dp));
    //delete
    word1.erase(i, 1);
    res = min(res, 1 + dfs(word1, word2, i, n-1, m, dp));
    dp[i][n-i] = res;
    return res;
}


class Solution {
public:

    int minDistance(string word1, string word2){
        int n=word1.size(), m=word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i=0; i<=m; i++) dp[n][i] = m-i;
        for (int i=0; i<=n; i++) dp[i][m] = n-i;
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                if(word1[i]==word2[j]) dp[i][j]=dp[i+1][j+1];
                else dp[i][j] = 1 + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
            }
        }
        return dp[0][0];
    }

    int minDistanceSlow(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<vector<int>> dp(m, vector<int>(n+1, -1));
        return dfs(word1, word2, 0, n, m, dp);
    }
};

#endif //LEETCODE_72_EDITDISTANCE_H
