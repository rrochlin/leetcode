//
// Created by Robert Rochlin on 8/19/24.
//

#ifndef LEETCODE_210_COURSESCHEDULEII_H
#define LEETCODE_210_COURSESCHEDULEII_H
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

bool dfs(unordered_map<int, vector<int>>& deps, set<int>& visited, set<int>& taken, int i, vector<int>& order) {
    if(visited.find(i)!=visited.end()) return false;
    if(taken.find(i)!=taken.end()) return true;
    visited.insert(i);
    for(int j : deps[i]){
        if(!dfs(deps, visited, taken, j, order)) return false;
    }
    visited.erase(i);
    taken.insert(i);
    order.push_back(i);
    deps[i].clear();
    return true;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> deps;
        for(int i=0; i<prerequisites.size(); i++){
            deps[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        set<int> visited;
        set<int> taken;
        vector<int> order;

        for(int i=0; i<numCourses; i++){
            if(!dfs(deps, visited, taken, i, order)) return {};
        }

        return order;
    }
};

#endif //LEETCODE_210_COURSESCHEDULEII_H
