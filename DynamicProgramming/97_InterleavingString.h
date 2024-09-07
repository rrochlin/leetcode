//
// Created by Robert Rochlin on 9/4/24.
//

#ifndef LEETCODE_97_INTERLEAVINGSTRING_H
#define LEETCODE_97_INTERLEAVINGSTRING_H

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int ns1 = s1.size(), ns2 = s2.size(), ns3 = s3.size();
        if (ns1 + ns2 != ns3) return false;
        vector<vector<bool>> dp(ns1 + 1, vector<bool>(ns2 + 1));
        for (int i = ns1; i >= 0; i--) {
            for (int j = ns2; j >= 0; j--) {
                if ((i + j == ns3) ||
                    (i < ns1 && s1[i] == s3[i + j] && dp[i + 1][j]) ||
                    (j < ns2 && s2[j] == s3[i + j] && dp[i][j + 1])) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
    bool isInterleave2(string s1, string s2, string s3) {
        int ns1 = s1.size(), ns2 = s2.size(), ns3 = s3.size();
        if(ns1+ns2!=ns3) return false;
        if(ns1==0||ns2==0) return s1==s3 || s2==s3;
        stack<array<int, 2>> stack{{{0, 0}}};
        vector<vector<bool>> visited (ns1+1, vector<bool> (ns2+1, false));
        while (!stack.empty()) {
            auto sp = stack.top();
            if (sp[0] + sp[1] == ns3) return true;
            stack.pop();
            if(sp[0] < ns1 && sp[1] < ns2 && visited[sp[0]][sp[1]]) continue;
            if (sp[0] < ns1 && s1[sp[0]] == s3[sp[0] + sp[1]]) {
                stack.push({sp[0] + 1, sp[1]});
            }
            if (sp[1] < ns2 && s2[sp[1]] == s3[sp[0] + sp[1]])  {
                stack.push({sp[0], sp[1] + 1});
            }
            visited[sp[0]][sp[1]] = true;
        }
        return false;
    }
};

#endif //LEETCODE_97_INTERLEAVINGSTRING_H
