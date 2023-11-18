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
      int l=0,r=vecl.size()-1,k,i;
      int goal = (vecl.size()+vecm.size())/2;
      bool odd = (vecl.size()+vecm.size())%2==1;
      while(l<=r){
        k = (l+r)/2;
        i = findNextSmallest(vecm, vecl[k]);
        if (i + k + 2 > goal) r=k-1;
        else if (i + k + 2 == goal) break;
        else l=k+1;
      }
      if (i+k+2==goal){
        if(odd) return vecl[k]>vecm[i] ? vecl[k] : vecm[i];
        if (vecl[k] > vecm[i]){
          if (k == vecl.size()-1) return (vecm[i+1]+vecl[k])/2.0;
          if (i == vecm.size()-1) return (vecl[k] + vecl[k+1])/2.0;
          if (vecl[k] < vecm[i+1]) return (vecm[i+1] + vecl[k])/2.0;
          return (vecl[k] + vecl[k+1]);
        }
        else {

        }

      }
      return 0;
    }
    int findNextSmallest(std::vector<int>& m, int t){
      int l=0,r=m.size();
      // expecting no equality
      int k;
      while (l<r){
        k = (l+r)/2;
        if (m[k] < t) l=k+1;
        else r=k;
      }
      return std::min(l,(int)m.size()-1);
    }
};

int main(){
    Solution sol;
    // std::vector<int> vec({});
    // std::vector<int> vec2({2,3});
    // std::cout<<sol.findMedianSortedArrays(vec, vec2)<<'\n';
    // std::vector<int> vectest({1,2,5,6,7,8,20,30,40,50});
    std::vector<int> vec21({1,2});
    std::vector<int> vec22({3,4});
    std::cout<<sol.findMedianSortedArrays(vec21, vec22)<<'\n';
}; 
