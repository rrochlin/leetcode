//
// Created by Robert Rochlin on 8/18/24.
//
#include "207_CourseSchedule.h"
#include <iostream>

int main(int argc, const char* argv[]){
    auto sol = new Solution();
    vector<vector<int>> prereqs {{0,1},{0,2},{1,2}};
    cout<<sol->canFinish(3,prereqs);
}
