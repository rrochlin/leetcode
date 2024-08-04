//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Solution {
public:
    double avg(int a, int b) {return (a+b)/2.0;}

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
      int ll=0,lr=vecl.size(),lk;
      int ml,mr,mk;
      int goal = (vecl.size()+vecm.size()-1)/2;
      bool odd = (vecl.size()+vecm.size())%2==1;
      while(ll<lr){
        lk = (ll+lr)/2;
        ml=0;
        mr = vecm.size();
        while (ml<mr){
          mk = (ml+mr)/2;
          if (vecm[mk] < vecl[lk]) ml=mk+1;
          else mr=mk;
        }
        if (ml + lk < goal) ll=lk+1;
        else lr=lk;
      }
      if (lk+ml<goal){
        if (odd) return vecm[mk];
        if (vecm.size()-1==mk) return avg(vecm[mk],vecl[lk+1]);
        if (vecl.size()-1==lk) return avg(vecm[mk],vecm[mk+1]);
        return avg(vecm[mk],std::min(vecm[mk+1],vecl[lk+1]));
      }
      if (lk+ml==goal){
        if (odd) return vecl[lk];
        if (vecm.size()-1==mk) return avg(vecl[lk],vecl[lk+1]);
        if (vecl.size()-1==lk) return avg(vecl[lk],vecm[mk+1]);
        return avg(vecl[lk],std::min(vecm[mk+1],vecl[lk+1]));
      }
      if (odd) return vecm[goal-lk];
      if (goal-lk == vecm.size()-1) return avg(vecm[goal-lk],vecl[lk]);
      return avg(vecm[goal-lk], std::min(vecm[goal-lk+1],vecl[lk]));
    }
};
int main(){
    Solution sol;
    // std::vector<int> vec01({-1,0,1,2,3,4,5});
    // std::vector<int> vec02({6,7});
    // std::cout<<sol.findMedianSortedArrays(vec01, vec02)<<'\n';
    // std::vector<int> vec21({1,2,19});
    // std::vector<int> vec22({3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18});
    // std::cout<<sol.findMedianSortedArrays(vec21, vec22)<<'\n';
    // std::vector<int> vec31({1,3});
    // std::vector<int> vec32({2,7});
    // std::cout<<sol.findMedianSortedArrays(vec31, vec32)<<'\n';
    // std::vector<int> vec41({1,2});
    // std::vector<int> vec42({-1,3});
    // std::cout<<sol.findMedianSortedArrays(vec41, vec42)<<'\n';
    // std::vector<int> vec51({1,2});
    // std::vector<int> vec52({1,1});
    // std::cout<<sol.findMedianSortedArrays(vec51, vec52)<<'\n';
    // std::vector<int> vec61({0,0,0,0,0});
    // std::vector<int> vec62({-1,0,0,0,0,1});
    // std::cout<<sol.findMedianSortedArrays(vec61, vec62)<<'\n';
    std::vector<int> vec71({100001});
    std::vector<int> vec72({100000});
    std::cout<<sol.findMedianSortedArrays(vec71, vec72)<<'\n';
}; 
