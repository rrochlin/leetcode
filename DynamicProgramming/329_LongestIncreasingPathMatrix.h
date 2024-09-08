//
// Created by Robert Rochlin on 9/7/24.
//

#ifndef LEETCODE_329_LONGESTINCREASINGPATHMATRIX_H
#define LEETCODE_329_LONGESTINCREASINGPATHMATRIX_H
#include <vector>
#include <algorithm>
using namespace std;
static vector<array<int, 2>> directions = {{{1,0}, {0,1}, {-1, 0}, {0,-1}}};

int explore(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int n, int m){
    if(dp[i][j]>0) return dp[i][j];
    int res = 1;
    for(auto d : directions){
        if(d[0]+i<0 || d[0]+i>=n || d[1]+j<0 || d[1]+j>=m) continue;
        if(matrix[i][j] < matrix[d[0]+i][d[1]+j]) {
            res = max(res, 1 + explore(matrix, dp, d[0]+i, d[1]+j, n, m));
        }
    }
    dp[i][j] = res;
    return res;
}

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m=matrix[0].size(), res=0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(int t=explore(matrix, dp, i, j, n, m); t > res) res = t;
            }
        }
        return res;
    }
};

#endif //LEETCODE_329_LONGESTINCREASINGPATHMATRIX_H
