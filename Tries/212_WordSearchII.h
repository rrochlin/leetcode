//
// Created by RobertRochlin on 8/16/2024.
//

#ifndef LEETCODE_212_WORDSEARCHII_H
#define LEETCODE_212_WORDSEARCHII_H
#include <bits/stdc++.h>
#include "208_ImplementTrie_PrefixTree.h"
using namespace std;


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto trie = new Trie();
        for (auto w : words) trie->insert(w);
        vector<string> found;
        // now DFS through the board and keep track of the words found
        return found;
    }

};


#endif //LEETCODE_212_WORDSEARCHII_H
