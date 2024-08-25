//
// Created by Robert Rochlin on 8/19/24.
//
#include "139_WordBreak.h"
#include <iostream>

int main(int argc, const char* argv[]){
    auto sol = new Solution;
    auto s = "cars";
    vector<string> words {"car","ca","rs"};
    cout<<sol->wordBreak(s, words);
}