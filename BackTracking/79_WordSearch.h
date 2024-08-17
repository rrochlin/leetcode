//
// Created by Robert Rochlin on 8/16/24.
//

#ifndef LEETCODE_79_WORDSEARCH_H
#define LEETCODE_79_WORDSEARCH_H
#include <vector>
#include <set>
#include <pair>
using namespace std;

bool helper(vector<vector<char>>& board, string& word, int wordIdx, int i, int j, int& m, int& n, set<pair<int,int>> path) {
    if(word[wordIdx]==board[i][j]) {
        if(wordIdx==word.size()) return true;
        if(path.find({i+1, j})==path.end() && i+1<m && helper(board, word, wordIdx+1,))
    }
}

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board[0].size();
        int n = board.size();
        return helper(board, word, 0, 0, 0, m, n);
    }
};
#endif //LEETCODE_79_WORDSEARCH_H
