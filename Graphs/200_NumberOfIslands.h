//
// Created by Robert Rochlin on 8/18/24.
//

#ifndef LEETCODE_200_NUMBEROFISLANDS_H
#define LEETCODE_200_NUMBEROFISLANDS_H
#include <vector>
using namespace std;

void dft(vector<vector<char>> &grid, int x, int y, int &m, int &n){
    if(x<0 || y<0 || x>=m || y>=n || grid[x][y] != '1') return;
    grid[x][y]='#';
    dft(grid, x+1, y, m ,n);
    dft(grid, x-1, y, m ,n);
    dft(grid, x, y+1, m ,n);
    dft(grid, x, y-1, m ,n);
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count=0;
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1') {
                    dft(grid, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};
#endif //LEETCODE_200_NUMBEROFISLANDS_H
