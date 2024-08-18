//
// Created by Robert Rochlin on 8/18/24.
//
#include "200_NumberOfIslands.h"
#include <iostream>

int main(int argc, const char* argv[]){
    auto sol = new Solution();
    vector<vector<char>> grid {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout<<sol->numIslands(grid);
}
