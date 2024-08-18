//
// Created by Robert Rochlin on 8/18/24.
//

#ifndef LEETCODE_286_WALLSANDGATES_H
#define LEETCODE_286_WALLSANDGATES_H
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        int m=rooms.size(), n=rooms[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for (int i=0; i<4; i++){
                int x=row+dirs[i].first, y=col+dirs[i].second;
                if(x<0 || y<0 || x>=m || y>=n || rooms[x][y]!=INT_MAX) continue;
                rooms[x][y] = rooms[row][col] + 1;
                q.push({x,y});
            }

        }
    }

    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
};

#endif //LEETCODE_286_WALLSANDGATES_H
