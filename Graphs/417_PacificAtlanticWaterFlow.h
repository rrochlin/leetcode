//
// Created by Robert Rochlin on 8/18/24.
//

#ifndef LEETCODE_417_PACIFICATLANTICWATERFLOW_H
#define LEETCODE_417_PACIFICATLANTICWATERFLOW_H
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, int m, int n){
    visited[x][y] = true;
    if(x+1<m && !visited[x+1][y]  && grid[x+1][y] >= grid[x][y]) dfs(grid, visited, x+1, y, m, n);
    if(x>0   && !visited[x-1][y]  && grid[x-1][y] >= grid[x][y]) dfs(grid, visited, x-1, y, m, n);
    if(y+1<n && !visited[x][y+1]  && grid[x][y+1] >= grid[x][y]) dfs(grid, visited, x, y+1, m, n);
    if(y>0   && !visited[x][y-1]  && grid[x][y-1] >= grid[x][y]) dfs(grid, visited, x, y-1, m, n);
}


class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m , vector<bool>(n));

        for(int i=0;i<n;i++){
            dfs(heights, pacific, 0, i, m, n);
            dfs(heights, atlantic, m-1, i, m, n);
        }
        for(int j=0;j<m;j++){
            dfs(heights, pacific, j, 0, m, n);
            dfs(heights, atlantic, j, n-1, m, n);
        }

        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};

#endif //LEETCODE_417_PACIFICATLANTICWATERFLOW_H
