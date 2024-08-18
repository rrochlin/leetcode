//
// Created by Robert Rochlin on 8/18/24.
//

#ifndef LEETCODE_994_ROTTINGORANGES_H
#define LEETCODE_994_ROTTINGORANGES_H
#include <vector>
#include <queue>
#include <utility>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh_oranges=0;
        int m=grid.size(), n=grid[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh_oranges++;
            }
        }
        if(fresh_oranges==0) return 0;
        int min_time=-1;
        queue<pair<int, int>> q2;
        queue<pair<int, int>> *curr = &q;
        queue<pair<int, int>> *next = &q2;
        while(!curr->empty()){
            int row=curr->front().first, col=curr->front().second;
            curr->pop();
            for (int i=0; i<4; i++){
                int x=row+dirs[i].first, y=col+dirs[i].second;
                if(x<0||y<0||x>=m||y>=n||grid[x][y]!=1) continue;
                grid[x][y]=2;
                next->push({x,y});
                fresh_oranges--;
            }
            if(curr->empty()){
                auto temp = curr;
                curr=next;
                next=temp;
                min_time++;
            }
        }
        return fresh_oranges==0 ? min_time : -1;
    }
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
};

#endif //LEETCODE_994_ROTTINGORANGES_H
