//
// Created by Robert Rochlin on 8/18/24.
//

#ifndef LEETCODE_659_MAXAREAISLAND_H
#define LEETCODE_659_MAXAREAISLAND_H

#include <vector>
using namespace std;

void dft(vector<vector<int>> &grid, int &count, int x, int y, int &m, int &n){
    if(x<0 || y<0 || x>=m || y>=n || !grid[x][y]) return;
    count++;
    grid[x][y] = 0;
    dft(grid, count, x+1, y, m, n);
    dft(grid, count, x-1, y, m, n);
    dft(grid, count, x, y+1, m, n);
    dft(grid, count, x, y-1, m, n);
}

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int max=0;
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]) {
                    int count = 0;
                    dft(grid, count, i, j, m, n);
                    if(count>max) max=count;
                }
            }
        }
        return max;
    }
};

#endif //LEETCODE_659_MAXAREAISLAND_H
