//
// Created by Robert Rochlin on 8/18/24.
//

#ifndef LEETCODE_207_COURSESCHEDULE_H
#define LEETCODE_207_COURSESCHEDULE_H
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

bool dfs(unordered_map<int, vector<int>>& dep, set<int>& visited, int i){
    visited.insert(i);
    if(dep[i].empty()) return true;
    for(int j : dep[i]){
        if(dep[j].empty()) continue;
        if(visited.find(j)!=visited.end() || !dfs(dep, visited, j)) return false;
    }
    dep[i].clear();
    return true;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> dep(numCourses);
        for (int i=0; i<prerequisites.size(); i++) dep[prerequisites[i][0]].push_back(prerequisites[i][1]);
        for (int i=0; i<numCourses; i++) {
            set<int> visited;
            if (!dfs(dep, visited, i)) return false;
        }
        return true;
    }
};

#endif //LEETCODE_207_COURSESCHEDULE_H
