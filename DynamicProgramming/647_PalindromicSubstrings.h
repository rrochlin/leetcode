//
// Created by Robert Rochlin on 8/20/24.
//

#ifndef LEETCODE_647_PALINDROMICSUBSTRINGS_H
#define LEETCODE_647_PALINDROMICSUBSTRINGS_H
#include <string>
using namespace std;

void middleOut(string& s, int i, int j, int& pals){
    while(i>=0 && j<s.size() && s[i]==s[j]){
        i--;
        j++;
        pals++;
    }
}

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n==1) return 1;
        int pals = 1;
        for(int i=0; i<n-1; i++){
            middleOut(s, i, i, pals);
            middleOut(s, i, i+1, pals);
        }
        return pals;
    }
};


#endif //LEETCODE_647_PALINDROMICSUBSTRINGS_H
