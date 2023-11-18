//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& l, std::vector<int>& m) {
      // handle edge cases
      if(l.empty()){
        if (m.size()%2==1) return m[m.size()/2];
        return (m[m.size()/2-1] + m[m.size()/2])/2.0 ;
      }
      if(m.empty()){
        if (l.size()%2==1) return l[l.size()/2];
        return (l[l.size()/2-1] + l[l.size()/2])/2.0 ;
      }
      int ll=0,ml=0,lr=l.size()-1,mr=m.size()-1,mk,lk;
      while (ll<=lr || ml<=mr){
        lk = (ll+lr)/2;
        mk = (ml+mr)/2;
        if (l[lk] < m[mk]) {ll=lk+1; mr=mk-1;}
        else {lr=lk-1; ml=mk+1;}
      }
      return 0;
    }
};

int main(){
    Solution sol;
    // std::vector<int> vec({});
    // std::vector<int> vec2({2,3});
    // std::cout<<sol.findMedianSortedArrays(vec, vec2)<<'\n';
    std::vector<int> vec21({1,2});
    std::vector<int> vec22({3,4});
    std::cout<<sol.findMedianSortedArrays(vec21, vec22)<<'\n';
}; 
