//
// Created by Robert Rochlin on 8/20/24.
//

#ifndef LEETCODE_91_DECODEWAYS_H
#define LEETCODE_91_DECODEWAYS_H
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

int helper(string& s, int i, int n, unordered_map<int, int>& m){
    if(i<n && s[i]=='0') return 0;
    if(m.find(i)!=m.end()) return m[i];
    bool cond = s[i]=='1' || s[i]=='2' && i+1 < n && s[i+1]<'7';
    int res = helper(s, i+1, n, m);
    if(cond) res += helper(s, i+2, n, m);
    m[i] = res;
    return res;
}

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==1) return s[0]!='0';
        unordered_map<int, int> m{{n, 1},{n+1, 0}};
        return helper(s, 0, n, m);
    }
};

#endif //LEETCODE_91_DECODEWAYS_H
