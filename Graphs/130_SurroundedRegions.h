//
// Created by Robert Rochlin on 8/18/24.
//

#ifndef LEETCODE_130_SURROUNDEDREGIONS_H
#define LEETCODE_130_SURROUNDEDREGIONS_H
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, int i, int j, int m, int n){
    if(board[i][j]=='X') return;
    visited[i][j] = true;
    if(i+1<m && !visited[i+1][j]) dfs(board, visited, i+1, j, m, n);
    if(i>0   && !visited[i-1][j]) dfs(board, visited, i-1, j, m, n);
    if(j+1<n && !visited[i][j+1]) dfs(board, visited, i, j+1, m, n);
    if(j>0   && !visited[i][j-1]) dfs(board, visited, i, j-1, m, n);
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i=0; i<m; i++) {
            dfs(board, visited, i, 0, m, n);
            dfs(board, visited, i, n-1, m, n);
        }
        for (int j=0; j<n; j++) {
            dfs(board, visited, 0, j, m, n);
            dfs(board, visited, m-1, j, m, n);
        }
        for (int i=1; i<m-1; i++){
            for (int j=1; j<n-1; j++){
                if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
            }
        }
    }
};

#endif //LEETCODE_130_SURROUNDEDREGIONS_H
