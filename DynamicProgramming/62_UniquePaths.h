//
// Created by Robert Rochlin on 8/27/24.
//

#ifndef LEETCODE_62_UNIQUEPATHS_H
#define LEETCODE_62_UNIQUEPATHS_H
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(min(m,n)==1) return 1;
        vector<vector<int>> dp(m, vector<int>(n,1));
        for(int k=1; k<min(m,n); k++){
            for(int i=k; i<n; i++) dp[k][i] = dp[k-1][i] + dp[k][i-1];
            for(int j=k; j<m; j++) dp[k][j] = dp[j][k-1] + dp[j-1][k];
        }
        return dp[m-1][n-1];
    }
};

#endif //LEETCODE_62_UNIQUEPATHS_H
