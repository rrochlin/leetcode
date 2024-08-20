//
// Created by Robert Rochlin on 8/19/24.
//

#ifndef LEETCODE_261_GRAPHVALIDTREE_H
#define LEETCODE_261_GRAPHVALIDTREE_H
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        for(int i=0; i<edges.size(); i++) {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }

        stack<pair<int,int>> s({{edges[0][0], -1}});
        set<int> visited;
        while(!s.empty()){
            int top = s.top().first;
            if(m.find(top)==m.end()) return false;
            int from = s.top().second;
            s.pop();
            for(int i : m[top]) {
                if(i!=from) s.push({i,top});
            }
            m.erase(top);
        }
        return m.empty();

    }
};

#endif //LEETCODE_261_GRAPHVALIDTREE_H
