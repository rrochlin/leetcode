//
// Created by Robert Rochlin on 8/1/24.
//
#include <vector>

int binary_search_leftmost(std::vector<int> &A, int T){
    int L = 0;
    int R = A.size();
    while(L < R) {
        int m = ((L + R) / 2);
        if (A[m]< T) L = m + 1;
        else R = m;
    }
    return L;
}

#include "HelperFunctions.h"
