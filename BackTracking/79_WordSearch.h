//
// Created by Robert Rochlin on 8/16/24.
//

#ifndef LEETCODE_79_WORDSEARCH_H
#define LEETCODE_79_WORDSEARCH_H
#include <vector>
using namespace std;

bool helper(vector<vector<char>>& board, string& word, int wordIdx, int i, int j, int& rows, int& cols) {
    if(i<0 || j<0 || i >= rows || j >= cols || board[i][j] != word[wordIdx]) return false;
    board[i][j]='.';
    if(wordIdx >= word.size()-1) return true;
    if (helper(board, word, wordIdx+1, i+1, j, rows, cols) ||
        helper(board, word, wordIdx+1, i-1, j, rows, cols) ||
        helper(board, word, wordIdx+1, i, j+1, rows, cols) ||
        helper(board, word, wordIdx+1, i, j-1, rows, cols)
        ) return true;
    board[i][j] = word[wordIdx];
    return false;
}

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i=0; i < rows; i++){
            for (int j=0; j < cols; j++){
                if(word[0]==board[i][j] && helper(board, word, 0, i, j, rows, cols)) return true;
            }
        }
        return false;
    }
};
#endif //LEETCODE_79_WORDSEARCH_H
