//
// Created by Robert Rochlin on 8/20/24.
//

#ifndef LEETCODE_5_LONGESTPALINDROMICSUBSTRING_H
#define LEETCODE_5_LONGESTPALINDROMICSUBSTRING_H
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

void is_palindrome(string& s, int i, int j, int& length, int& start){

    while(i>=0 && j<s.size() && s[i]==s[j]){
        i--;
        j++;
    }
    if(j-i-1>length) {
        length=j-i-1;
        start=i+1;
    }
}

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        int length=1;
        int start=0;
        for (int i=0; i<n-1; i++){
            is_palindrome(s, i, i, length, start);
            is_palindrome(s, i, i+1, length, start);
        }
        return s.substr(start, length);
    }
};

#endif //LEETCODE_5_LONGESTPALINDROMICSUBSTRING_H
