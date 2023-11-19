//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& vecl, std::vector<int>& vecm) {
      // handle edge cases
      if(vecl.empty()){
        if (vecm.size()%2==1) return vecm[vecm.size()/2];
        return (vecm[vecm.size()/2-1] + vecm[vecm.size()/2])/2.0 ;
      }
      if(vecm.empty()){
        if (vecl.size()%2==1) return vecl[vecl.size()/2];
        return (vecl[vecl.size()/2-1] + vecl[vecl.size()/2])/2.0 ;
      }
      int ll=0,lr=vecl.size()-1,lk,i;
      int ml=0,mr=vecm.size()-1,mk;
      int goal = (vecl.size()+vecm.size())/2;
      bool odd = (vecl.size()+vecm.size())%2==1;
      while(ll<=lr){
        lk = (ll+lr)/2;
        while (ml<mr){
          mk = (ml+mr)/2;
          if (vecm[mk] < vecl[lk]) ml=mk+1;
          else mr=mk;
        }
        i = std::min(ml,(int)vecm.size()-1);
        if (i + lk + 1 > goal) lr=lk-1;
        // else if (i + lk + 1 == goal) break;
        else ll=lk+1;
      }
      // median was found
      if (i + lk + 1 == goal){
        if(odd) return std::max(vecl[lk],vecm[i]);
        if (vecl[lk] > vecm[i]){
          if (lk == vecl.size()-1) return (vecl[lk]+vecm[i])/2.0;
          if (i == vecm.size()-1) return (vecl[lk]+vecm[lk+1])/2.0;
          return (vecl[lk] + std::min(vecm[i+1],vecl[lk+1]));
        }
        // if i+lk+1==goal but m[i]>l[lk] i==0 k==l.size()

        return (vecm[i] + vecl[lk])/2.0;
      }
      // median was not found, array l was exhausted
      if(odd) return vecm[goal-lk];
      return (vecm[goal-lk-1]+vecm[goal-lk])/2.0;
    }
};

int main(){
    Solution sol;
    std::vector<int> vec({1,3});
    std::vector<int> vec2({2});
    std::cout<<sol.findMedianSortedArrays(vec, vec2)<<'\n';
    // std::vector<int> vectest({1,2,5,6,7,8,20,30,40,50});
    std::vector<int> vec21({1,2});
    std::vector<int> vec22({3,4});
    std::cout<<sol.findMedianSortedArrays(vec21, vec22)<<'\n';
    std::vector<int> vec31({1,3});
    std::vector<int> vec32({2,7});
    std::cout<<sol.findMedianSortedArrays(vec31, vec32)<<'\n';
    std::vector<int> vec41({1,2});
    std::vector<int> vec42({-1,3});
    std::cout<<sol.findMedianSortedArrays(vec41, vec42)<<'\n';
}; 
